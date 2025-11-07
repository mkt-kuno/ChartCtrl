# High-speed Charting Control

このリポジトリは、Cédric Moonenによって開発された高速チャートコントロールのクローンリポジトリです。

## オリジナルについて

- **オリジナル記事**: [High-speed Charting Control - CodeProject](https://www.codeproject.com/articles/High-speed-Charting-Control)
- **オリジナル作者**: Cédric Moonen (cedric_moonen@hotmail.com)
- **ライセンス**: [The Code Project Open License (CPOL)](https://www.codeproject.com/cpol)

## 概要

このコントロールは、MFC（Microsoft Foundation Classes）ベースのC++で開発された高速なチャート表示コントロールです。データの連続的な流れを表示する必要があるプロジェクトのために開発され、大量のデータを高速に表示できるように最適化されています。

## 主な機能

- **高速描画**: 軸が固定されている場合、高速にデータをプロットできます
- **無制限のシリーズ**: メモリが許す限り無制限の数のシリーズを追加可能
- **無制限のデータ量**: シリーズごとに無制限のデータポイントを扱えます
- **多様なシリーズタイプ**: 
  - 折れ線グラフ（Line）
  - 散布図（Point）
  - サーフェス
  - 棒グラフ（Bar）
  - ローソク足（Candlestick）
  - ガントチャート
- **最大4軸**: 左、下、右、上の4つの軸をサポート
- **様々な軸タイプ**: 標準軸、対数軸、日時軸
- **高いカスタマイズ性**: 色、タイトル、ラベル、フォントなど
- **インタラクティブ機能**: 
  - マウスズーム
  - パン（移動）
  - カーソル機能
  - スクロールバー
- **UNICODE対応**
- **印刷と画像保存のサポート**

## 必要な環境

- Visual C++ 6.0以降
- MFC（Microsoft Foundation Classes）
- RTTI（Run-Time Type Information）を有効にする必要があります

> **重要**: コントロールは内部で動的キャストを使用しているため、RTTIが有効になっている必要があります。VC6ではデフォルトで無効になっているため、プロジェクト設定で有効にしてください（プロジェクト設定 → "C/C++" タブ → "C++ language" カテゴリ → "Enable Run-Time Type Information (RTTI)" をチェック）。

## 使用方法

### 手動で挿入する場合

1. ダイアログヘッダーファイルの先頭に `#include "ChartCtrl.h"` を追加
2. ダイアログクラスに `CChartCtrl` 型の変数を追加
3. ダイアログクラスの `OnInitDialog` で、コントロールの `Create` メソッドを呼び出す

### リソースエディタを使用する場合

1. ダイアログリソースにカスタムコントロールを追加し、`Class` 属性に `ChartCtrl` を指定
2. ちらつきを防ぐため、`WS_CLIPCHILDREN` スタイル（0x02000000L）を設定
3. ダイアログヘッダーファイルの先頭に `#include "ChartCtrl.h"` を追加
4. ダイアログクラスに `CChartCtrl` 型の変数を追加
5. `DoDataExchange` 関数に `DDX_Control` 行を追加

### 基本的な使用例

```cpp
void CMyClass::Init()
{
    // 軸を作成（シリーズを追加する前に必須）
    CChartStandardAxis* pBottomAxis = 
        m_ChartCtrl.CreateStandardAxis(CChartCtrl::BottomAxis);
    CChartStandardAxis* pLeftAxis = 
        m_ChartCtrl.CreateStandardAxis(CChartCtrl::LeftAxis);
    
    // 軸の範囲を設定
    pBottomAxis->SetMinMax(0, 10);
    pLeftAxis->SetMinMax(0, 100);
    
    // 折れ線グラフを作成
    CChartLineSerie* pLineSeries = m_ChartCtrl.CreateLineSerie();
    
    // データを追加
    double XValues[10], YValues[10];
    for (int i = 0; i < 10; i++)
    {
        XValues[i] = i;
        YValues[i] = i * i;
    }
    pLineSeries->SetPoints(XValues, YValues, 10);
}
```

## ドキュメント

詳細なドキュメントはDoxygenで生成されています。オリジナルの記事からダウンロード可能です。

## 謝辞

このコントロールは、Cédric Moonenによる長時間の開発と努力の成果です。このコードを利用できることに深く感謝いたします。また、このコントロールの開発に貢献された以下の方々にも感謝いたします：

- toxcct
- Chris Maunder
- Kevin Hoffman
- jerminator-jp
- Laurie Gellatly
- Eugene Pustovoyt
- Andrej Ritter
- Nick Holgate
- Nick Schultz
- Johann Obermayr
- Pierre Schramm
- Kevin Winter
- Bruno Lavier（特別な感謝）

## 免責事項

このコントロールは「現状のまま」提供されます。商用・非商用を問わず、コンパイルされた形式で使用できます。ソースコードは、作者の同意を得た上で変更することができます。

このコードは保証なしで提供されます。使用によって発生した損害や時間の損失について、作者は一切の責任を負いません。

## ライセンス

このプロジェクトは[The Code Project Open License (CPOL)](https://www.codeproject.com/cpol)の下でライセンスされています。詳細については、`ライセンス.md`をご覧ください。

---

**注意**: これはクローンリポジトリです。私はこのコードの開発者ではありません。オリジナルの作者であるCédric Moonenに感謝いたします。
