cmake_minimum_required(VERSION 3.16)
project(ChartCtrl VERSION 1.0.0 LANGUAGES CXX)

# 単一構成ジェネレータ（Ninja等）の場合のデフォルトビルドタイプ
if(NOT CMAKE_CONFIGURATION_TYPES AND NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

# C++標準の設定
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# MFCの使用を有効化
set(CMAKE_MFC_FLAG 2)  # 2 = Use MFC in a shared DLL

# ソース/ヘッダーファイルの自動収集（CONFIGURE_DEPENDSでファイル追加に追従）
file(GLOB CHARTCTRL_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)
file(GLOB CHARTCTRL_HEADERS CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h"
)
file(GLOB CHARTCTRL_INLINE_FILES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.inl"
)

# 静的ライブラリの作成
add_library(ChartCtrl STATIC
    ${CHARTCTRL_SOURCES}
    ${CHARTCTRL_HEADERS}
)

# インクルードディレクトリの設定
target_include_directories(ChartCtrl
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# コンパイルオプションの設定
if(MSVC)
    target_compile_options(ChartCtrl PRIVATE
        /W3                    # 警告レベル3
        /permissive-          # 標準準拠モード
        /Zc:__cplusplus       # __cplusplus マクロを正しく設定
    )
    
    # Unicode サポート
    target_compile_definitions(ChartCtrl PUBLIC
        UNICODE
        _UNICODE
    )
endif()

# ライブラリのプロパティ設定
set_target_properties(ChartCtrl PROPERTIES
    OUTPUT_NAME "ChartCtrl"
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    DEBUG_POSTFIX "d"
)

# インストール設定（オプション）
install(TARGETS ChartCtrl
    EXPORT ChartCtrlTargets
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
    DESTINATION include/ChartCtrl
    FILES_MATCHING 
        PATTERN "*.h"
)
