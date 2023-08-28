import Pod.Float
import Raymath.Core
import Raylib.Structures

open Pod (Float32)
open Raymath (Vector2)
open Raylib (Rectangle)

namespace Raygui

/-! # Constants -/

def versionMajor := 4
def versionMinor := 0
def versionPatch := 0
def version := "4.0-dev"

def scrollbarLeftSide : Nat := 0
def scrollbarRightSide : Nat := 1

/-- Size of icons in pixels (squared) -/
def iconSize := 16
/-- Maximum number of icons -/
def iconMaxIcons := 256
/-- Maximum length of icon name id -/
def iconMaxNameLength := 32
def iconDataElements := iconSize * iconSize / 32

/-- Maximum number of standard controls -/
def maxControls := 16
/-- Maximum number of standard properties -/
def maxPropsBase := 16
/-- Maximum number of extended properties -/
def maxPropsExtended := 8

/-! # Types -/

inductive GuiState.Is : UInt32 -> Prop where
  | normal : GuiState.Is 0
  | focused : GuiState.Is 1
  | pressed : GuiState.Is 2
  | disabled : GuiState.Is 3

def GuiState : Type := Subtype GuiState.Is

inductive GuiTextAlignment.Is : UInt32 -> Prop where
  | left : GuiTextAlignment.Is 0
  | center : GuiTextAlignment.Is 1
  | right : GuiTextAlignment.Is 2

def GuiTextAlignment : Type := Subtype GuiTextAlignment.Is

inductive GuiControl.Is : UInt32 -> Prop where
  | default : GuiControl.Is 0
  | label : GuiControl.Is 1
  | button : GuiControl.Is 2
  | toggle : GuiControl.Is 3
  | slider : GuiControl.Is 4
  | progressbar : GuiControl.Is 5
  | checkbox : GuiControl.Is 6
  | combobox : GuiControl.Is 7
  | dropdownbox : GuiControl.Is 8
  | textbox : GuiControl.Is 9
  | valuebox : GuiControl.Is 10
  | spinner : GuiControl.Is 11
  | listview : GuiControl.Is 12
  | colorpicker : GuiControl.Is 13
  | scrollbar : GuiControl.Is 14
  | statusbar : GuiControl.Is 15

def GuiControl : Type := Subtype GuiControl.Is

def GuiControlProperty.borderColorNormal : UInt32 := 0
def GuiControlProperty.baseColorNormal : UInt32 := 1
def GuiControlProperty.textColorNormal : UInt32 := 2
def GuiControlProperty.borderColorFocused : UInt32 := 3
def GuiControlProperty.baseColorFocused : UInt32 := 4
def GuiControlProperty.textColorFocused : UInt32 := 5
def GuiControlProperty.borderColorPressed : UInt32 := 6
def GuiControlProperty.baseColorPressed : UInt32 := 7
def GuiControlProperty.textColorPressed : UInt32 := 8
def GuiControlProperty.borderColorDisabled : UInt32 := 9
def GuiControlProperty.baseColorDisabled : UInt32 := 10
def GuiControlProperty.textColorDisabled : UInt32 := 11
def GuiControlProperty.borderWidth : UInt32 := 12
def GuiControlProperty.textPadding : UInt32 := 13
def GuiControlProperty.textAlignment : UInt32 := 14
def GuiControlProperty.reserved : UInt32 := 15

def GuiDefaultProperty.textSize : UInt32 := 16
def GuiDefaultProperty.textSpacing : UInt32 := 17
def GuiDefaultProperty.lineColor : UInt32 := 18
def GuiDefaultProperty.backgroundColor : UInt32 := 19
def GuiDefaultProperty.textLineSpacing : UInt32 := 20

def GuiToggleProperty.groupPadding : UInt32 := 16

/-- Slider size of internal bar -/
def GuiSliderProperty.sliderWidth : UInt32 := 16
/-- Slider/SliderBar internal bar padding -/
def GuiSliderProperty.sliderPadding : UInt32 := 17

/-- ProgressBar internal padding -/
def GuiProgressBarProperty.progressPadding : UInt32 := 16

def GuiScrollBarProperty.arrowsSize : UInt32 := 16
def GuiScrollBarProperty.arrowsVisible : UInt32 := 17
def GuiScrollBarProperty.scrollSliderPadding : UInt32 := 18
def GuiScrollBarProperty.scrollSliderSize : UInt32 := 19
def GuiScrollBarProperty.scrollPadding : UInt32 := 20
def GuiScrollBarProperty.scrollSpeed : UInt32 := 21

def GuiCheckBoxProperty.checkPadding : UInt32 := 16

/-- ComboBox right button width -/
def GuiComboBoxProperty.comboButtonWidth : UInt32 := 16
/-- ComboBox button separation -/
def GuiComboBoxProperty.comboButtonSpacing : UInt32 := 17

/-- DropdownBox arrow separation from border and items -/
def GuiDropdownBoxProperty.arrowPadding : UInt32 := 16
/-- DropdownBox items separation -/
def GuiDropdownBoxProperty.dropdownItemsSpacing : UInt32 := 17

/-- TextBox/TextBoxMulti/ValueBox/Spinner inner text padding -/
def GuiTextBoxProperty.textInnerPadding : UInt32 := 16
/-- TextBoxMulti lines separation -/
def GuiTextBoxProperty.textLinesSpacing : UInt32 := 17
/-- TextBoxMulti vertical alignment: 0-CENTERED, 1-UP, 2-DOWN -/
def GuiTextBoxProperty.textAlignmentVertical : UInt32 := 18
/-- TextBox supports multiple lines -/
def GuiTextBoxProperty.textMultiline : UInt32 := 19
/-- TextBox wrap mode for multiline: 0-NO_WRAP, 1-CHAR_WRAP, 2-WORD_WRAP -/
def GuiTextBoxProperty.textWrapMode : UInt32 := 20
/-- TextBox is readonly, no editable -/
def GuiTextBoxProperty.textReadonly : UInt32 := 21

/-- Spinner left/right buttons width -/
def GuiSpinnerProperty.spinButtonWidth : UInt32 := 16
/-- Spinner buttons separation -/
def GuiSpinnerProperty.spinButtonSpacing : UInt32 := 17

/-- ListView items height -/
def GuiListViewProperty.listItemsHeight : UInt32 := 16
/-- ListView items separation -/
def GuiListViewProperty.listItemsSpacing : UInt32 := 17
/-- ListView scrollbar size (usually width) -/
def GuiListViewProperty.scrollbarWidth : UInt32 := 18
/-- ListView scrollbar side (0-left, 1-right) -/
def GuiListViewProperty.scrollbarSide : UInt32 := 19

def GuiColorPickerProperty.colorSelectorSize : UInt32 := 16
/-- ColorPicker right hue bar width -/
def GuiColorPickerProperty.huebarWidth : UInt32 := 17
/-- ColorPicker right hue bar separation from panel -/
def GuiColorPickerProperty.huebarPadding : UInt32 := 18
/-- ColorPicker right hue bar selector height -/
def GuiColorPickerProperty.huebarSelectorHeight : UInt32 := 19
/-- ColorPicker right hue bar selector overflow -/
def GuiColorPickerProperty.huebarSelectorOverflow : UInt32 := 20

structure GuiStyleProp where
  controlId : GuiControl
  propertyId : UInt32
  propertyValue : UInt32

inductive GuiIconName.Is : UInt32 -> Prop where
  | iconNone : GuiIconName.Is 0
  | iconFolderFileOpen : GuiIconName.Is 1
  | iconFileSaveClassic : GuiIconName.Is 2
  | iconFolderOpen : GuiIconName.Is 3
  | iconFolderSave : GuiIconName.Is 4
  | iconFileOpen : GuiIconName.Is 5
  | iconFileSave : GuiIconName.Is 6
  | iconFileExport : GuiIconName.Is 7
  | iconFileAdd : GuiIconName.Is 8
  | iconFileDelete : GuiIconName.Is 9
  | iconFiletypeText : GuiIconName.Is 10
  | iconFiletypeAudio : GuiIconName.Is 11
  | iconFiletypeImage : GuiIconName.Is 12
  | iconFiletypePlay : GuiIconName.Is 13
  | iconFiletypeVideo : GuiIconName.Is 14
  | iconFiletypeInfo : GuiIconName.Is 15
  | iconFileCopy : GuiIconName.Is 16
  | iconFileCut : GuiIconName.Is 17
  | iconFilePaste : GuiIconName.Is 18
  | iconCursorHand : GuiIconName.Is 19
  | iconCursorPointer : GuiIconName.Is 20
  | iconCursorClassic : GuiIconName.Is 21
  | iconPencil : GuiIconName.Is 22
  | iconPencilBig : GuiIconName.Is 23
  | iconBrushClassic : GuiIconName.Is 24
  | iconBrushPainter : GuiIconName.Is 25
  | iconWaterDrop : GuiIconName.Is 26
  | iconColorPicker : GuiIconName.Is 27
  | iconRubber : GuiIconName.Is 28
  | iconColorBucket : GuiIconName.Is 29
  | iconTextT : GuiIconName.Is 30
  | iconTextA : GuiIconName.Is 31
  | iconScale : GuiIconName.Is 32
  | iconResize : GuiIconName.Is 33
  | iconFilterPoint : GuiIconName.Is 34
  | iconFilterBilinear : GuiIconName.Is 35
  | iconCrop : GuiIconName.Is 36
  | iconCropAlpha : GuiIconName.Is 37
  | iconSquareToggle : GuiIconName.Is 38
  | iconSymmetry : GuiIconName.Is 39
  | iconSymmetryHorizontal : GuiIconName.Is 40
  | iconSymmetryVertical : GuiIconName.Is 41
  | iconLens : GuiIconName.Is 42
  | iconLensBig : GuiIconName.Is 43
  | iconEyeOn : GuiIconName.Is 44
  | iconEyeOff : GuiIconName.Is 45
  | iconFilterTop : GuiIconName.Is 46
  | iconFilter : GuiIconName.Is 47
  | iconTargetPoint : GuiIconName.Is 48
  | iconTargetSmall : GuiIconName.Is 49
  | iconTargetBig : GuiIconName.Is 50
  | iconTargetMove : GuiIconName.Is 51
  | iconCursorMove : GuiIconName.Is 52
  | iconCursorScale : GuiIconName.Is 53
  | iconCursorScaleRight : GuiIconName.Is 54
  | iconCursorScaleLeft : GuiIconName.Is 55
  | iconUndo : GuiIconName.Is 56
  | iconRedo : GuiIconName.Is 57
  | iconReredo : GuiIconName.Is 58
  | iconMutate : GuiIconName.Is 59
  | iconRotate : GuiIconName.Is 60
  | iconRepeat : GuiIconName.Is 61
  | iconShuffle : GuiIconName.Is 62
  | iconEmptybox : GuiIconName.Is 63
  | iconTarget : GuiIconName.Is 64
  | iconTargetSmallFill : GuiIconName.Is 65
  | iconTargetBigFill : GuiIconName.Is 66
  | iconTargetMoveFill : GuiIconName.Is 67
  | iconCursorMoveFill : GuiIconName.Is 68
  | iconCursorScaleFill : GuiIconName.Is 69
  | iconCursorScaleRightFill : GuiIconName.Is 70
  | iconCursorScaleLeftFill : GuiIconName.Is 71
  | iconUndoFill : GuiIconName.Is 72
  | iconRedoFill : GuiIconName.Is 73
  | iconReredoFill : GuiIconName.Is 74
  | iconMutateFill : GuiIconName.Is 75
  | iconRotateFill : GuiIconName.Is 76
  | iconRepeatFill : GuiIconName.Is 77
  | iconShuffleFill : GuiIconName.Is 78
  | iconEmptyboxSmall : GuiIconName.Is 79
  | iconBox : GuiIconName.Is 80
  | iconBoxTop : GuiIconName.Is 81
  | iconBoxTopRight : GuiIconName.Is 82
  | iconBoxRight : GuiIconName.Is 83
  | iconBoxBottomRight : GuiIconName.Is 84
  | iconBoxBottom : GuiIconName.Is 85
  | iconBoxBottomLeft : GuiIconName.Is 86
  | iconBoxLeft : GuiIconName.Is 87
  | iconBoxTopLeft : GuiIconName.Is 88
  | iconBoxCenter : GuiIconName.Is 89
  | iconBoxCircleMask : GuiIconName.Is 90
  | iconPot : GuiIconName.Is 91
  | iconAlphaMultiply : GuiIconName.Is 92
  | iconAlphaClear : GuiIconName.Is 93
  | iconDithering : GuiIconName.Is 94
  | iconMipmaps : GuiIconName.Is 95
  | iconBoxGrid : GuiIconName.Is 96
  | iconGrid : GuiIconName.Is 97
  | iconBoxCornersSmall : GuiIconName.Is 98
  | iconBoxCornersBig : GuiIconName.Is 99
  | iconFourBoxes : GuiIconName.Is 100
  | iconGridFill : GuiIconName.Is 101
  | iconBoxMultisize : GuiIconName.Is 102
  | iconZoomSmall : GuiIconName.Is 103
  | iconZoomMedium : GuiIconName.Is 104
  | iconZoomBig : GuiIconName.Is 105
  | iconZoomAll : GuiIconName.Is 106
  | iconZoomCenter : GuiIconName.Is 107
  | iconBoxDotsSmall : GuiIconName.Is 108
  | iconBoxDotsBig : GuiIconName.Is 109
  | iconBoxConcentric : GuiIconName.Is 110
  | iconBoxGridBig : GuiIconName.Is 111
  | iconOkTick : GuiIconName.Is 112
  | iconCross : GuiIconName.Is 113
  | iconArrowLeft : GuiIconName.Is 114
  | iconArrowRight : GuiIconName.Is 115
  | iconArrowDown : GuiIconName.Is 116
  | iconArrowUp : GuiIconName.Is 117
  | iconArrowLeftFill : GuiIconName.Is 118
  | iconArrowRightFill : GuiIconName.Is 119
  | iconArrowDownFill : GuiIconName.Is 120
  | iconArrowUpFill : GuiIconName.Is 121
  | iconAudio : GuiIconName.Is 122
  | iconFx : GuiIconName.Is 123
  | iconWave : GuiIconName.Is 124
  | iconWaveSinus : GuiIconName.Is 125
  | iconWaveSquare : GuiIconName.Is 126
  | iconWaveTriangular : GuiIconName.Is 127
  | iconCrossSmall : GuiIconName.Is 128
  | iconPlayerPrevious : GuiIconName.Is 129
  | iconPlayerPlayBack : GuiIconName.Is 130
  | iconPlayerPlay : GuiIconName.Is 131
  | iconPlayerPause : GuiIconName.Is 132
  | iconPlayerStop : GuiIconName.Is 133
  | iconPlayerNext : GuiIconName.Is 134
  | iconPlayerRecord : GuiIconName.Is 135
  | iconMagnet : GuiIconName.Is 136
  | iconLockClose : GuiIconName.Is 137
  | iconLockOpen : GuiIconName.Is 138
  | iconClock : GuiIconName.Is 139
  | iconTools : GuiIconName.Is 140
  | iconGear : GuiIconName.Is 141
  | iconGearBig : GuiIconName.Is 142
  | iconBin : GuiIconName.Is 143
  | iconHandPointer : GuiIconName.Is 144
  | iconLaser : GuiIconName.Is 145
  | iconCoin : GuiIconName.Is 146
  | iconExplosion : GuiIconName.Is 147
  | icon1up : GuiIconName.Is 148
  | iconPlayer : GuiIconName.Is 149
  | iconPlayerJump : GuiIconName.Is 150
  | iconKey : GuiIconName.Is 151
  | iconDemon : GuiIconName.Is 152
  | iconTextPopup : GuiIconName.Is 153
  | iconGearEx : GuiIconName.Is 154
  | iconCrack : GuiIconName.Is 155
  | iconCrackPoints : GuiIconName.Is 156
  | iconStar : GuiIconName.Is 157
  | iconDoor : GuiIconName.Is 158
  | iconExit : GuiIconName.Is 159
  | iconMode2d : GuiIconName.Is 160
  | iconMode3d : GuiIconName.Is 161
  | iconCube : GuiIconName.Is 162
  | iconCubeFaceTop : GuiIconName.Is 163
  | iconCubeFaceLeft : GuiIconName.Is 164
  | iconCubeFaceFront : GuiIconName.Is 165
  | iconCubeFaceBottom : GuiIconName.Is 166
  | iconCubeFaceRight : GuiIconName.Is 167
  | iconCubeFaceBack : GuiIconName.Is 168
  | iconCamera : GuiIconName.Is 169
  | iconSpecial : GuiIconName.Is 170
  | iconLinkNet : GuiIconName.Is 171
  | iconLinkBoxes : GuiIconName.Is 172
  | iconLinkMulti : GuiIconName.Is 173
  | iconLink : GuiIconName.Is 174
  | iconLinkBroke : GuiIconName.Is 175
  | iconTextNotes : GuiIconName.Is 176
  | iconNotebook : GuiIconName.Is 177
  | iconSuitcase : GuiIconName.Is 178
  | iconSuitcaseZip : GuiIconName.Is 179
  | iconMailbox : GuiIconName.Is 180
  | iconMonitor : GuiIconName.Is 181
  | iconPrinter : GuiIconName.Is 182
  | iconPhotoCamera : GuiIconName.Is 183
  | iconPhotoCameraFlash : GuiIconName.Is 184
  | iconHouse : GuiIconName.Is 185
  | iconHeart : GuiIconName.Is 186
  | iconCorner : GuiIconName.Is 187
  | iconVerticalBars : GuiIconName.Is 188
  | iconVerticalBarsFill : GuiIconName.Is 189
  | iconLifeBars : GuiIconName.Is 190
  | iconInfo : GuiIconName.Is 191
  | iconCrossline : GuiIconName.Is 192
  | iconHelp : GuiIconName.Is 193
  | iconFiletypeAlpha : GuiIconName.Is 194
  | iconFiletypeHome : GuiIconName.Is 195
  | iconLayersVisible : GuiIconName.Is 196
  | iconLayers : GuiIconName.Is 197
  | iconWindow : GuiIconName.Is 198
  | iconHidpi : GuiIconName.Is 199
  | iconFiletypeBinary : GuiIconName.Is 200
  | iconHex : GuiIconName.Is 201
  | iconShield : GuiIconName.Is 202
  | iconFileNew : GuiIconName.Is 203
  | iconFolderAdd : GuiIconName.Is 204
  | iconAlarm : GuiIconName.Is 205
  | iconCpu : GuiIconName.Is 206
  | iconRom : GuiIconName.Is 207
  | iconStepOver : GuiIconName.Is 208
  | iconStepInto : GuiIconName.Is 209
  | iconStepOut : GuiIconName.Is 210
  | iconRestart : GuiIconName.Is 211
  | iconBreakpointOn : GuiIconName.Is 212
  | iconBreakpointOff : GuiIconName.Is 213
  | iconBurgerMenu : GuiIconName.Is 214
  | iconCaseSensitive : GuiIconName.Is 215
  | iconRegExp : GuiIconName.Is 216
  | iconFolder : GuiIconName.Is 217
  | iconFile : GuiIconName.Is 218
  | iconSandTimer : GuiIconName.Is 219
  | icon220 : GuiIconName.Is 220
  | icon221 : GuiIconName.Is 221
  | icon222 : GuiIconName.Is 222
  | icon223 : GuiIconName.Is 223
  | icon224 : GuiIconName.Is 224
  | icon225 : GuiIconName.Is 225
  | icon226 : GuiIconName.Is 226
  | icon227 : GuiIconName.Is 227
  | icon228 : GuiIconName.Is 228
  | icon229 : GuiIconName.Is 229
  | icon230 : GuiIconName.Is 230
  | icon231 : GuiIconName.Is 231
  | icon232 : GuiIconName.Is 232
  | icon233 : GuiIconName.Is 233
  | icon234 : GuiIconName.Is 234
  | icon235 : GuiIconName.Is 235
  | icon236 : GuiIconName.Is 236
  | icon237 : GuiIconName.Is 237
  | icon238 : GuiIconName.Is 238
  | icon239 : GuiIconName.Is 239
  | icon240 : GuiIconName.Is 240
  | icon241 : GuiIconName.Is 241
  | icon242 : GuiIconName.Is 242
  | icon243 : GuiIconName.Is 243
  | icon244 : GuiIconName.Is 244
  | icon245 : GuiIconName.Is 245
  | icon246 : GuiIconName.Is 246
  | icon247 : GuiIconName.Is 247
  | icon248 : GuiIconName.Is 248
  | icon249 : GuiIconName.Is 249
  | icon250 : GuiIconName.Is 250
  | icon251 : GuiIconName.Is 251
  | icon252 : GuiIconName.Is 252
  | icon253 : GuiIconName.Is 253
  | icon254 : GuiIconName.Is 254
  | icon255 : GuiIconName.Is 255

def GuiIconName : Type := Subtype GuiIconName.Is

inductive GuiPropertyElement.Is : UInt32 → Prop where
  | border : GuiPropertyElement.Is 0
  | base : GuiPropertyElement.Is 1
  | text : GuiPropertyElement.Is 2
  | other : GuiPropertyElement.Is 3

def GuiPropertyElement : Type := Subtype GuiPropertyElement.Is


/-! # Functions -/

/-- -/
@[extern "lean_raygui__GuiEnable"]
opaque enable : BaseIO Unit

/-- -/
@[extern "lean_raygui__GuiDisable"]
opaque disable : BaseIO Unit

/-- -/
@[extern "lean_raygui__GuiLock"]
opaque lock : BaseIO Unit

/-- -/
@[extern "lean_raygui__GuiUnlock"]
opaque unlock : BaseIO Unit

/-- -/
@[extern "lean_raygui__GuiIsLocked"]
opaque isLocked : BaseIO Unit

/-- -/
@[extern "lean_raygui__GuiSetAlpha"]
opaque setAlpha : BaseIO Unit

/-- -/
@[extern "lean_raygui__GuiSetState"]
opaque setState : BaseIO Unit

/-- -/
@[extern "lean_raygui__GuiGetState"]
opaque getState : BaseIO Unit

/-- -/
@[extern "lean_raygui__GuiSetFont"]
opaque setFont : BaseIO Unit

/-- -/
@[extern "lean_raygui__GuiGetFont"]
opaque getFont : BaseIO Unit

/-- -/
@[extern "lean_raygui__GuiSetStyle"]
opaque setStyle : BaseIO Unit

/-- -/
@[extern "lean_raygui__GuiGetStyle"]
opaque getStyle : BaseIO Unit

/-- -/
@[extern "lean_raygui__GuiLoadStyle"]
opaque loadStyle : BaseIO Unit

/-- -/
@[extern "lean_raygui__GuiLoadStyleDefault"]
opaque loadStyleDefault : BaseIO Unit

/-- -/
@[extern "lean_raygui__GuiEnableTooltip"]
opaque enableTooltip : BaseIO Unit

/-- -/
@[extern "lean_raygui__GuiDisableTooltip"]
opaque disableTooltip : BaseIO Unit

/-- -/
@[extern "lean_raygui__GuiSetTooltip"]
opaque setTooltip : BaseIO Unit

/-- -/
@[extern "lean_raygui__GuiIconText"]
opaque iconText : BaseIO Unit

/-- -/
@[extern "lean_raygui__GuiSetIconScale"]
opaque setIconScale : BaseIO Unit

/-- -/
@[extern "lean_raygui__GuiGetIcons"]
opaque getIcons : BaseIO Unit

/-- -/
@[extern "lean_raygui__GuiLoadIcons"]
opaque loadIcons : BaseIO Unit

/-- -/
@[extern "lean_raygui__GuiDrawIcon"]
opaque drawIcon : BaseIO Unit


/-! ## Controls -/

/-! ### Container/separator controls -/

/-- -/
@[extern "lean_raygui__GuiWindowBox"]
opaque windowBox (bounds : Rectangle) : BaseIO UInt32

/-- -/
@[extern "lean_raygui__GuiGroupBox"]
opaque groupBox (bounds : Rectangle) : BaseIO UInt32

/-- -/
@[extern "lean_raygui__GuiLine"]
opaque line (bounds : Rectangle) : BaseIO UInt32

/-- -/
@[extern "lean_raygui__GuiPanel"]
opaque panel (bounds : Rectangle) : BaseIO UInt32

/-- -/
@[extern "lean_raygui__GuiTabBar"]
opaque tabBar (bounds : Rectangle) : BaseIO UInt32

/-- -/
@[extern "lean_raygui__GuiScrollPanel"]
opaque scrollPanel (bounds : Rectangle) : BaseIO UInt32


/-! ### Basic controls -/

/-- Label control, shows text -/
@[extern "lean_raygui__GuiLabel"]
opaque label (bounds : Rectangle) : BaseIO UInt32

/-- Button control, returns true when clicked -/
@[extern "lean_raygui__GuiButton"]
opaque button (bounds : Rectangle) : BaseIO UInt32

/-- Label button control, show true when clicked -/
@[extern "lean_raygui__GuiLabelButton"]
opaque labelButton (bounds : Rectangle) : BaseIO UInt32

/-- Toggle Button control, returns true when active -/
@[extern "lean_raygui__GuiToggle"]
opaque toggle (bounds : Rectangle) : BaseIO UInt32

/-- Toggle Group control, returns active toggle index -/
@[extern "lean_raygui__GuiToggleGroup"]
opaque toggleGroup (bounds : Rectangle) : BaseIO UInt32

/-- Toggle Slider control, returns true when clicked -/
@[extern "lean_raygui__GuiToggleSlider"]
opaque toggleSlider (bounds : Rectangle) : BaseIO UInt32

/-- Check Box control, returns true when active -/
@[extern "lean_raygui__GuiCheckBox"]
opaque checkBox (bounds : Rectangle) : BaseIO UInt32

/-- Combo Box control, returns selected item index -/
@[extern "lean_raygui__GuiComboBox"]
opaque comboBox (bounds : Rectangle) : BaseIO UInt32


/-- -/
@[extern "lean_raygui__GuiDropdownBox"]
opaque dropdownBox (bounds : Rectangle) : BaseIO UInt32

/-- -/
@[extern "lean_raygui__GuiSpinner"]
opaque spinner (bounds : Rectangle) : BaseIO UInt32

/-- -/
@[extern "lean_raygui__GuiValueBox"]
opaque valueBox (bounds : Rectangle) : BaseIO UInt32

/-- -/
@[extern "lean_raygui__GuiTextBox"]
opaque textBox (bounds : Rectangle) : BaseIO UInt32


/-- -/
@[extern "lean_raygui__GuiSlider"]
opaque slider (bounds : Rectangle) : BaseIO UInt32

/-- -/
@[extern "lean_raygui__GuiSliderBar"]
opaque sliderBar (bounds : Rectangle) : BaseIO UInt32

/-- -/
@[extern "lean_raygui__GuiProgressBar"]
opaque progressBar (bounds : Rectangle) : BaseIO UInt32

/-- -/
@[extern "lean_raygui__GuiStatusBar"]
opaque statusBar (bounds : Rectangle) : BaseIO UInt32

/-- -/
@[extern "lean_raygui__GuiDummyRec"]
opaque dummyRec (bounds : Rectangle) : BaseIO UInt32

/-- -/
@[extern "lean_raygui__GuiGrid"]
opaque grid (bounds : Rectangle) : BaseIO UInt32


/-! ### Advance controls set -/

/-- -/
@[extern "lean_raygui__GuiListView"]
opaque listView (bounds : Rectangle) : BaseIO UInt32

/-- -/
@[extern "lean_raygui__GuiListViewEx"]
opaque listViewEx (bounds : Rectangle) : BaseIO UInt32

/-- -/
@[extern "lean_raygui__GuiMessageBox"]
opaque messageBox (bounds : Rectangle) : BaseIO UInt32

/-- -/
@[extern "lean_raygui__GuiTextInputBox"]
opaque textInputBox (bounds : Rectangle) : BaseIO UInt32

/-- -/
@[extern "lean_raygui__GuiColorPicker"]
opaque colorPicker (bounds : Rectangle) : BaseIO UInt32

/-- -/
@[extern "lean_raygui__GuiColorPanel"]
opaque colorPanel (bounds : Rectangle) : BaseIO UInt32

/-- -/
@[extern "lean_raygui__GuiColorBarAlpha"]
opaque colorBarAlpha (bounds : Rectangle) : BaseIO UInt32

/-- -/
@[extern "lean_raygui__GuiColorBarHue"]
opaque colorBarHue (bounds : Rectangle) : BaseIO UInt32

/-- -/
@[extern "lean_raygui__GuiColorPickerHSV"]
opaque colorPickerHsv (bounds : Rectangle) : BaseIO UInt32

/-- -/
@[extern "lean_raygui__GuiColorPanelHSV"]
opaque colorPanelHsv (bounds : Rectangle) : BaseIO UInt32
