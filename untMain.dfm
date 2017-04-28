object frmMain: TfrmMain
  Left = 192
  Top = 107
  AlphaBlend = True
  AlphaBlendValue = 192
  AutoSize = True
  BorderStyle = bsNone
  ClientHeight = 41
  ClientWidth = 185
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsStayOnTop
  KeyPreview = True
  OldCreateOrder = False
  OnCreate = FormCreate
  OnKeyDown = FormKeyDown
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 185
    Height = 41
    BevelInner = bvLowered
    TabOrder = 0
    object trkAlpha: TTrackBar
      Left = 0
      Top = 8
      Width = 177
      Height = 33
      Max = 255
      Min = 32
      Orientation = trHorizontal
      Frequency = 16
      Position = 32
      SelEnd = 0
      SelStart = 0
      TabOrder = 0
      ThumbLength = 15
      TickMarks = tmBottomRight
      TickStyle = tsAuto
      OnChange = trkAlphaChange
    end
  end
  object ApplicationEvents1: TApplicationEvents
    OnMessage = ApplicationEvents1Message
    Left = 112
    Top = 8
  end
  object Timer1: TTimer
    Interval = 1
    OnTimer = Timer1Timer
    Left = 40
    Top = 8
  end
end
