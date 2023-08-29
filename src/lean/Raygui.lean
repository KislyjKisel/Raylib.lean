import Pod.Float
import Raymath.Core
import Raylib.Structures

open Pod (Float32)
open Raymath (Vector2 Vector3)
open Raylib (Color Rectangle)

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

inductive State.Is : UInt32 -> Prop where
  | normal : State.Is 0
  | focused : State.Is 1
  | pressed : State.Is 2
  | disabled : State.Is 3

def State : Type := Subtype State.Is

namespace State

def normal : State := Subtype.mk 0 State.Is.normal
def focused : State := Subtype.mk 1 State.Is.focused
def pressed : State := Subtype.mk 2 State.Is.pressed
def disabled : State := Subtype.mk 3 State.Is.disabled

end State

instance : Inhabited State := ⟨State.normal⟩

inductive TextAlignment.Is : UInt32 -> Prop where
  | left : TextAlignment.Is 0
  | center : TextAlignment.Is 1
  | right : TextAlignment.Is 2

def TextAlignment : Type := Subtype TextAlignment.Is

namespace TextAlignment

def left : TextAlignment := Subtype.mk 0 TextAlignment.Is.left
def center : TextAlignment := Subtype.mk 1 TextAlignment.Is.center
def right : TextAlignment := Subtype.mk 2 TextAlignment.Is.right

end TextAlignment

inductive Control.Is : UInt32 -> Prop where
  | default : Control.Is 0
  | label : Control.Is 1
  | button : Control.Is 2
  | toggle : Control.Is 3
  | slider : Control.Is 4
  | progressbar : Control.Is 5
  | checkbox : Control.Is 6
  | combobox : Control.Is 7
  | dropdownbox : Control.Is 8
  | textbox : Control.Is 9
  | valuebox : Control.Is 10
  | spinner : Control.Is 11
  | listview : Control.Is 12
  | colorpicker : Control.Is 13
  | scrollbar : Control.Is 14
  | statusbar : Control.Is 15

def Control : Type := Subtype Control.Is

namespace Control

def default : Control := Subtype.mk 0 Control.Is.default
def label : Control := Subtype.mk 1 Control.Is.label
def button : Control := Subtype.mk 2 Control.Is.button
def toggle : Control := Subtype.mk 3 Control.Is.toggle
def slider : Control := Subtype.mk 4 Control.Is.slider
def progressbar : Control := Subtype.mk 5 Control.Is.progressbar
def checkbox : Control := Subtype.mk 6 Control.Is.checkbox
def combobox : Control := Subtype.mk 7 Control.Is.combobox
def dropdownbox : Control := Subtype.mk 8 Control.Is.dropdownbox
def textbox : Control := Subtype.mk 9 Control.Is.textbox
def valuebox : Control := Subtype.mk 10 Control.Is.valuebox
def spinner : Control := Subtype.mk 11 Control.Is.spinner
def listview : Control := Subtype.mk 12 Control.Is.listview
def colorpicker : Control := Subtype.mk 13 Control.Is.colorpicker
def scrollbar : Control := Subtype.mk 14 Control.Is.scrollbar
def statusbar : Control := Subtype.mk 15 Control.Is.statusbar

end Control

def ControlProperty.borderColorNormal : UInt32 := 0
def ControlProperty.baseColorNormal : UInt32 := 1
def ControlProperty.textColorNormal : UInt32 := 2
def ControlProperty.borderColorFocused : UInt32 := 3
def ControlProperty.baseColorFocused : UInt32 := 4
def ControlProperty.textColorFocused : UInt32 := 5
def ControlProperty.borderColorPressed : UInt32 := 6
def ControlProperty.baseColorPressed : UInt32 := 7
def ControlProperty.textColorPressed : UInt32 := 8
def ControlProperty.borderColorDisabled : UInt32 := 9
def ControlProperty.baseColorDisabled : UInt32 := 10
def ControlProperty.textColorDisabled : UInt32 := 11
def ControlProperty.borderWidth : UInt32 := 12
def ControlProperty.textPadding : UInt32 := 13
def ControlProperty.textAlignment : UInt32 := 14
def ControlProperty.reserved : UInt32 := 15

def DefaultProperty.textSize : UInt32 := 16
def DefaultProperty.textSpacing : UInt32 := 17
def DefaultProperty.lineColor : UInt32 := 18
def DefaultProperty.backgroundColor : UInt32 := 19
def DefaultProperty.textLineSpacing : UInt32 := 20

def ToggleProperty.groupPadding : UInt32 := 16

/-- Slider size of internal bar -/
def SliderProperty.sliderWidth : UInt32 := 16
/-- Slider/SliderBar internal bar padding -/
def SliderProperty.sliderPadding : UInt32 := 17

/-- ProgressBar internal padding -/
def ProgressBarProperty.progressPadding : UInt32 := 16

def ScrollBarProperty.arrowsSize : UInt32 := 16
def ScrollBarProperty.arrowsVisible : UInt32 := 17
def ScrollBarProperty.scrollSliderPadding : UInt32 := 18
def ScrollBarProperty.scrollSliderSize : UInt32 := 19
def ScrollBarProperty.scrollPadding : UInt32 := 20
def ScrollBarProperty.scrollSpeed : UInt32 := 21

def CheckBoxProperty.checkPadding : UInt32 := 16

/-- ComboBox right button width -/
def ComboBoxProperty.comboButtonWidth : UInt32 := 16
/-- ComboBox button separation -/
def ComboBoxProperty.comboButtonSpacing : UInt32 := 17

/-- DropdownBox arrow separation from border and items -/
def DropdownBoxProperty.arrowPadding : UInt32 := 16
/-- DropdownBox items separation -/
def DropdownBoxProperty.dropdownItemsSpacing : UInt32 := 17

/-- TextBox/TextBoxMulti/ValueBox/Spinner inner text padding -/
def TextBoxProperty.textInnerPadding : UInt32 := 16
/-- TextBoxMulti lines separation -/
def TextBoxProperty.textLinesSpacing : UInt32 := 17
/-- TextBoxMulti vertical alignment: 0-CENTERED, 1-UP, 2-DOWN -/
def TextBoxProperty.textAlignmentVertical : UInt32 := 18
/-- TextBox supports multiple lines -/
def TextBoxProperty.textMultiline : UInt32 := 19
/-- TextBox wrap mode for multiline: 0-NO_WRAP, 1-CHAR_WRAP, 2-WORD_WRAP -/
def TextBoxProperty.textWrapMode : UInt32 := 20
/-- TextBox is readonly, no editable -/
def TextBoxProperty.textReadonly : UInt32 := 21

/-- Spinner left/right buttons width -/
def SpinnerProperty.spinButtonWidth : UInt32 := 16
/-- Spinner buttons separation -/
def SpinnerProperty.spinButtonSpacing : UInt32 := 17

/-- ListView items height -/
def ListViewProperty.listItemsHeight : UInt32 := 16
/-- ListView items separation -/
def ListViewProperty.listItemsSpacing : UInt32 := 17
/-- ListView scrollbar size (usually width) -/
def ListViewProperty.scrollbarWidth : UInt32 := 18
/-- ListView scrollbar side (0-left, 1-right) -/
def ListViewProperty.scrollbarSide : UInt32 := 19

def ColorPickerProperty.colorSelectorSize : UInt32 := 16
/-- ColorPicker right hue bar width -/
def ColorPickerProperty.huebarWidth : UInt32 := 17
/-- ColorPicker right hue bar separation from panel -/
def ColorPickerProperty.huebarPadding : UInt32 := 18
/-- ColorPicker right hue bar selector height -/
def ColorPickerProperty.huebarSelectorHeight : UInt32 := 19
/-- ColorPicker right hue bar selector overflow -/
def ColorPickerProperty.huebarSelectorOverflow : UInt32 := 20

structure StyleProp where
  controlId : Control
  propertyId : UInt32
  propertyValue : UInt32

inductive IconName.Is : UInt32 -> Prop where
  | iconNone : IconName.Is 0
  | iconFolderFileOpen : IconName.Is 1
  | iconFileSaveClassic : IconName.Is 2
  | iconFolderOpen : IconName.Is 3
  | iconFolderSave : IconName.Is 4
  | iconFileOpen : IconName.Is 5
  | iconFileSave : IconName.Is 6
  | iconFileExport : IconName.Is 7
  | iconFileAdd : IconName.Is 8
  | iconFileDelete : IconName.Is 9
  | iconFiletypeText : IconName.Is 10
  | iconFiletypeAudio : IconName.Is 11
  | iconFiletypeImage : IconName.Is 12
  | iconFiletypePlay : IconName.Is 13
  | iconFiletypeVideo : IconName.Is 14
  | iconFiletypeInfo : IconName.Is 15
  | iconFileCopy : IconName.Is 16
  | iconFileCut : IconName.Is 17
  | iconFilePaste : IconName.Is 18
  | iconCursorHand : IconName.Is 19
  | iconCursorPointer : IconName.Is 20
  | iconCursorClassic : IconName.Is 21
  | iconPencil : IconName.Is 22
  | iconPencilBig : IconName.Is 23
  | iconBrushClassic : IconName.Is 24
  | iconBrushPainter : IconName.Is 25
  | iconWaterDrop : IconName.Is 26
  | iconColorPicker : IconName.Is 27
  | iconRubber : IconName.Is 28
  | iconColorBucket : IconName.Is 29
  | iconTextT : IconName.Is 30
  | iconTextA : IconName.Is 31
  | iconScale : IconName.Is 32
  | iconResize : IconName.Is 33
  | iconFilterPoint : IconName.Is 34
  | iconFilterBilinear : IconName.Is 35
  | iconCrop : IconName.Is 36
  | iconCropAlpha : IconName.Is 37
  | iconSquareToggle : IconName.Is 38
  | iconSymmetry : IconName.Is 39
  | iconSymmetryHorizontal : IconName.Is 40
  | iconSymmetryVertical : IconName.Is 41
  | iconLens : IconName.Is 42
  | iconLensBig : IconName.Is 43
  | iconEyeOn : IconName.Is 44
  | iconEyeOff : IconName.Is 45
  | iconFilterTop : IconName.Is 46
  | iconFilter : IconName.Is 47
  | iconTargetPoint : IconName.Is 48
  | iconTargetSmall : IconName.Is 49
  | iconTargetBig : IconName.Is 50
  | iconTargetMove : IconName.Is 51
  | iconCursorMove : IconName.Is 52
  | iconCursorScale : IconName.Is 53
  | iconCursorScaleRight : IconName.Is 54
  | iconCursorScaleLeft : IconName.Is 55
  | iconUndo : IconName.Is 56
  | iconRedo : IconName.Is 57
  | iconReredo : IconName.Is 58
  | iconMutate : IconName.Is 59
  | iconRotate : IconName.Is 60
  | iconRepeat : IconName.Is 61
  | iconShuffle : IconName.Is 62
  | iconEmptybox : IconName.Is 63
  | iconTarget : IconName.Is 64
  | iconTargetSmallFill : IconName.Is 65
  | iconTargetBigFill : IconName.Is 66
  | iconTargetMoveFill : IconName.Is 67
  | iconCursorMoveFill : IconName.Is 68
  | iconCursorScaleFill : IconName.Is 69
  | iconCursorScaleRightFill : IconName.Is 70
  | iconCursorScaleLeftFill : IconName.Is 71
  | iconUndoFill : IconName.Is 72
  | iconRedoFill : IconName.Is 73
  | iconReredoFill : IconName.Is 74
  | iconMutateFill : IconName.Is 75
  | iconRotateFill : IconName.Is 76
  | iconRepeatFill : IconName.Is 77
  | iconShuffleFill : IconName.Is 78
  | iconEmptyboxSmall : IconName.Is 79
  | iconBox : IconName.Is 80
  | iconBoxTop : IconName.Is 81
  | iconBoxTopRight : IconName.Is 82
  | iconBoxRight : IconName.Is 83
  | iconBoxBottomRight : IconName.Is 84
  | iconBoxBottom : IconName.Is 85
  | iconBoxBottomLeft : IconName.Is 86
  | iconBoxLeft : IconName.Is 87
  | iconBoxTopLeft : IconName.Is 88
  | iconBoxCenter : IconName.Is 89
  | iconBoxCircleMask : IconName.Is 90
  | iconPot : IconName.Is 91
  | iconAlphaMultiply : IconName.Is 92
  | iconAlphaClear : IconName.Is 93
  | iconDithering : IconName.Is 94
  | iconMipmaps : IconName.Is 95
  | iconBoxGrid : IconName.Is 96
  | iconGrid : IconName.Is 97
  | iconBoxCornersSmall : IconName.Is 98
  | iconBoxCornersBig : IconName.Is 99
  | iconFourBoxes : IconName.Is 100
  | iconGridFill : IconName.Is 101
  | iconBoxMultisize : IconName.Is 102
  | iconZoomSmall : IconName.Is 103
  | iconZoomMedium : IconName.Is 104
  | iconZoomBig : IconName.Is 105
  | iconZoomAll : IconName.Is 106
  | iconZoomCenter : IconName.Is 107
  | iconBoxDotsSmall : IconName.Is 108
  | iconBoxDotsBig : IconName.Is 109
  | iconBoxConcentric : IconName.Is 110
  | iconBoxGridBig : IconName.Is 111
  | iconOkTick : IconName.Is 112
  | iconCross : IconName.Is 113
  | iconArrowLeft : IconName.Is 114
  | iconArrowRight : IconName.Is 115
  | iconArrowDown : IconName.Is 116
  | iconArrowUp : IconName.Is 117
  | iconArrowLeftFill : IconName.Is 118
  | iconArrowRightFill : IconName.Is 119
  | iconArrowDownFill : IconName.Is 120
  | iconArrowUpFill : IconName.Is 121
  | iconAudio : IconName.Is 122
  | iconFx : IconName.Is 123
  | iconWave : IconName.Is 124
  | iconWaveSinus : IconName.Is 125
  | iconWaveSquare : IconName.Is 126
  | iconWaveTriangular : IconName.Is 127
  | iconCrossSmall : IconName.Is 128
  | iconPlayerPrevious : IconName.Is 129
  | iconPlayerPlayBack : IconName.Is 130
  | iconPlayerPlay : IconName.Is 131
  | iconPlayerPause : IconName.Is 132
  | iconPlayerStop : IconName.Is 133
  | iconPlayerNext : IconName.Is 134
  | iconPlayerRecord : IconName.Is 135
  | iconMagnet : IconName.Is 136
  | iconLockClose : IconName.Is 137
  | iconLockOpen : IconName.Is 138
  | iconClock : IconName.Is 139
  | iconTools : IconName.Is 140
  | iconGear : IconName.Is 141
  | iconGearBig : IconName.Is 142
  | iconBin : IconName.Is 143
  | iconHandPointer : IconName.Is 144
  | iconLaser : IconName.Is 145
  | iconCoin : IconName.Is 146
  | iconExplosion : IconName.Is 147
  | icon1up : IconName.Is 148
  | iconPlayer : IconName.Is 149
  | iconPlayerJump : IconName.Is 150
  | iconKey : IconName.Is 151
  | iconDemon : IconName.Is 152
  | iconTextPopup : IconName.Is 153
  | iconGearEx : IconName.Is 154
  | iconCrack : IconName.Is 155
  | iconCrackPoints : IconName.Is 156
  | iconStar : IconName.Is 157
  | iconDoor : IconName.Is 158
  | iconExit : IconName.Is 159
  | iconMode2d : IconName.Is 160
  | iconMode3d : IconName.Is 161
  | iconCube : IconName.Is 162
  | iconCubeFaceTop : IconName.Is 163
  | iconCubeFaceLeft : IconName.Is 164
  | iconCubeFaceFront : IconName.Is 165
  | iconCubeFaceBottom : IconName.Is 166
  | iconCubeFaceRight : IconName.Is 167
  | iconCubeFaceBack : IconName.Is 168
  | iconCamera : IconName.Is 169
  | iconSpecial : IconName.Is 170
  | iconLinkNet : IconName.Is 171
  | iconLinkBoxes : IconName.Is 172
  | iconLinkMulti : IconName.Is 173
  | iconLink : IconName.Is 174
  | iconLinkBroke : IconName.Is 175
  | iconTextNotes : IconName.Is 176
  | iconNotebook : IconName.Is 177
  | iconSuitcase : IconName.Is 178
  | iconSuitcaseZip : IconName.Is 179
  | iconMailbox : IconName.Is 180
  | iconMonitor : IconName.Is 181
  | iconPrinter : IconName.Is 182
  | iconPhotoCamera : IconName.Is 183
  | iconPhotoCameraFlash : IconName.Is 184
  | iconHouse : IconName.Is 185
  | iconHeart : IconName.Is 186
  | iconCorner : IconName.Is 187
  | iconVerticalBars : IconName.Is 188
  | iconVerticalBarsFill : IconName.Is 189
  | iconLifeBars : IconName.Is 190
  | iconInfo : IconName.Is 191
  | iconCrossline : IconName.Is 192
  | iconHelp : IconName.Is 193
  | iconFiletypeAlpha : IconName.Is 194
  | iconFiletypeHome : IconName.Is 195
  | iconLayersVisible : IconName.Is 196
  | iconLayers : IconName.Is 197
  | iconWindow : IconName.Is 198
  | iconHidpi : IconName.Is 199
  | iconFiletypeBinary : IconName.Is 200
  | iconHex : IconName.Is 201
  | iconShield : IconName.Is 202
  | iconFileNew : IconName.Is 203
  | iconFolderAdd : IconName.Is 204
  | iconAlarm : IconName.Is 205
  | iconCpu : IconName.Is 206
  | iconRom : IconName.Is 207
  | iconStepOver : IconName.Is 208
  | iconStepInto : IconName.Is 209
  | iconStepOut : IconName.Is 210
  | iconRestart : IconName.Is 211
  | iconBreakpointOn : IconName.Is 212
  | iconBreakpointOff : IconName.Is 213
  | iconBurgerMenu : IconName.Is 214
  | iconCaseSensitive : IconName.Is 215
  | iconRegExp : IconName.Is 216
  | iconFolder : IconName.Is 217
  | iconFile : IconName.Is 218
  | iconSandTimer : IconName.Is 219
  | icon220 : IconName.Is 220
  | icon221 : IconName.Is 221
  | icon222 : IconName.Is 222
  | icon223 : IconName.Is 223
  | icon224 : IconName.Is 224
  | icon225 : IconName.Is 225
  | icon226 : IconName.Is 226
  | icon227 : IconName.Is 227
  | icon228 : IconName.Is 228
  | icon229 : IconName.Is 229
  | icon230 : IconName.Is 230
  | icon231 : IconName.Is 231
  | icon232 : IconName.Is 232
  | icon233 : IconName.Is 233
  | icon234 : IconName.Is 234
  | icon235 : IconName.Is 235
  | icon236 : IconName.Is 236
  | icon237 : IconName.Is 237
  | icon238 : IconName.Is 238
  | icon239 : IconName.Is 239
  | icon240 : IconName.Is 240
  | icon241 : IconName.Is 241
  | icon242 : IconName.Is 242
  | icon243 : IconName.Is 243
  | icon244 : IconName.Is 244
  | icon245 : IconName.Is 245
  | icon246 : IconName.Is 246
  | icon247 : IconName.Is 247
  | icon248 : IconName.Is 248
  | icon249 : IconName.Is 249
  | icon250 : IconName.Is 250
  | icon251 : IconName.Is 251
  | icon252 : IconName.Is 252
  | icon253 : IconName.Is 253
  | icon254 : IconName.Is 254
  | icon255 : IconName.Is 255

def IconName : Type := Subtype IconName.Is

inductive PropertyElement.Is : UInt32 → Prop where
  | border : PropertyElement.Is 0
  | base : PropertyElement.Is 1
  | text : PropertyElement.Is 2
  | other : PropertyElement.Is 3

def PropertyElement : Type := Subtype PropertyElement.Is


/-! # Functions -/

/-- Enable gui controls (global state) -/
@[extern "lean_raygui__GuiEnable"]
opaque enable : BaseIO Unit

/-- Disable gui controls (global state) -/
@[extern "lean_raygui__GuiDisable"]
opaque disable : BaseIO Unit

/-- Lock gui controls (global state) -/
@[extern "lean_raygui__GuiLock"]
opaque lock : BaseIO Unit

/-- Unlock gui controls (global state) -/
@[extern "lean_raygui__GuiUnlock"]
opaque unlock : BaseIO Unit

/-- Check if gui is locked (global state) -/
@[extern "lean_raygui__GuiIsLocked"]
opaque isLocked : BaseIO Bool

/-- Set gui controls alpha (global state), alpha goes from 0.0f to 1.0f -/
@[extern "lean_raygui__GuiSetAlpha"]
opaque setAlpha (alpha : Float32) : BaseIO Unit

/-- Set gui state (global state) -/
@[extern "lean_raygui__GuiSetState"]
opaque setState (state : State) : BaseIO Unit

/-- Get gui state (global state) -/
@[extern "lean_raygui__GuiGetState"]
opaque getState : BaseIO State

/-- Set gui custom font (global state) -/
@[extern "lean_raygui__GuiSetFont"]
opaque setFont (font : @& Raylib.Font) : BaseIO Unit

/-- Get gui custom font (global state) -/
@[extern "lean_raygui__GuiGetFont"]
opaque getFont : BaseIO Raylib.Font

/-- Set one style property -/
@[extern "lean_raygui__GuiSetStyle"]
opaque setStyle (control : Control) (property : UInt32) (value : UInt32) : BaseIO Unit

/-- Get one style property -/
@[extern "lean_raygui__GuiGetStyle"]
opaque getStyle (control : Control) (property : UInt32) : BaseIO UInt32

/-- Load style file over global style variable (.rgs) -/
@[extern "lean_raygui__GuiLoadStyle"]
opaque loadStyle (fileName : @& String) : BaseIO Unit

/-- Load style default over global style -/
@[extern "lean_raygui__GuiLoadStyleDefault"]
opaque loadStyleDefault : BaseIO Unit

/-- Enable gui tooltips (global state) -/
@[extern "lean_raygui__GuiEnableTooltip"]
opaque enableTooltip : BaseIO Unit

/-- Disable gui tooltips (global state) -/
@[extern "lean_raygui__GuiDisableTooltip"]
opaque disableTooltip : BaseIO Unit

/-- Set tooltip string -/
@[extern "lean_raygui__GuiSetTooltip"]
opaque setTooltip (tooltip : @& String) : BaseIO Unit

/-- Get text with icon id prepended (if supported) -/
@[extern "lean_raygui__GuiIconText"]
opaque iconText (iconId : IconName) (text : @& String) : BaseIO String

/-- Set default icon drawing size -/
@[extern "lean_raygui__GuiSetIconScale"]
opaque setIconScale (scale : UInt32) : BaseIO Unit

-- /-- Get raygui icons data pointer -/
-- @[extern "lean_raygui__GuiGetIcons"]
-- opaque getIcons : BaseIO Unit

/-- Load raygui icons file (.rgi) into internal icons data -/
@[extern "lean_raygui__GuiLoadIcons"]
opaque loadIcons (fileName : @& String) : BaseIO Unit

/-- Draw icon using pixel size at specified position -/
@[extern "lean_raygui__GuiDrawIcon"]
opaque drawIcon (iconId : IconName) (posX posY pixelSize : UInt32) (color : Color) : BaseIO Unit


/-! ## Controls -/

/-! ### Container/separator controls -/

/--
Window Box control, shows a window that can be closed.
Window close button clicked: returns true.
-/
@[extern "lean_raygui__GuiWindowBox"]
opaque windowBox (bounds : @& Rectangle) (title : @& String) : BaseIO Bool

/-- Group Box control with text name -/
@[extern "lean_raygui__GuiGroupBox"]
opaque groupBox (bounds : @& Rectangle) (text : @& String) : BaseIO Unit

/-- Line separator control, could contain text -/
@[extern "lean_raygui__GuiLine"]
opaque line (bounds : @& Rectangle) (text : @& String) : BaseIO Unit

/-- Panel control, useful to group controls -/
@[extern "lean_raygui__GuiPanel"]
opaque panel (bounds : @& Rectangle) (text : @& String) : BaseIO Unit

/-- Tab Bar control, returns TAB to be closed -/
@[extern "lean_raygui__GuiTabBar"]
opaque tabBar (bounds : @& Rectangle) (text : @& Array String) (active : UInt32) : BaseIO (Option UInt32)

/-- Scroll Panel control. Returns new scroll, view.  -/
@[extern "lean_raygui__GuiScrollPanel"]
opaque scrollPanel (bounds : @& Rectangle) (text : @& String) (content : @& Rectangle) (scroll : Vector2) (view : Rectangle) : BaseIO (Vector2 × Rectangle)


/-! ### Basic controls -/

/-- Label control, shows text -/
@[extern "lean_raygui__GuiLabel"]
opaque label (bounds : @& Rectangle) (text : @& String) : BaseIO Unit

/-- Button control, returns true when clicked -/
@[extern "lean_raygui__GuiButton"]
opaque button (bounds : @& Rectangle) (text : @& String) : BaseIO Bool

/-- Label button control, show true when clicked -/
@[extern "lean_raygui__GuiLabelButton"]
opaque labelButton (bounds : @& Rectangle) (text : @& String) : BaseIO Bool

/-- Toggle Button control, returns true when active -/
@[extern "lean_raygui__GuiToggle"]
opaque toggle (bounds : @& Rectangle) (text : @& String) (active : Bool) : BaseIO Bool

/-- Toggle Group control, returns active toggle index -/
@[extern "lean_raygui__GuiToggleGroup"]
opaque toggleGroup (bounds : @& Rectangle) (text : @& String) (active : UInt32) : BaseIO UInt32

/-- Toggle Slider control, returns true when clicked -/
@[extern "lean_raygui__GuiToggleSlider"]
opaque toggleSlider (bounds : @& Rectangle) (text : @& String) (active : UInt32) : BaseIO (Bool × UInt32)

/-- Check Box control, returns true when active -/
@[extern "lean_raygui__GuiCheckBox"]
opaque checkBox (bounds : @& Rectangle) (text : @& String) (checked : Bool) : BaseIO Bool

/-- Combo Box control, returns selected item index -/
@[extern "lean_raygui__GuiComboBox"]
opaque comboBox (bounds : @& Rectangle) (text : @& String) (active : UInt32) : BaseIO UInt32


/-- Dropdown Box control, returns selected item -/
@[extern "lean_raygui__GuiDropdownBox"]
opaque dropdownBox (bounds : @& Rectangle)  (text : @& String) (active : UInt32) (editMode : Bool) : BaseIO (Bool × UInt32)

/-- Spinner control, returns selected value -/
@[extern "lean_raygui__GuiSpinner"]
opaque spinner (bounds : @& Rectangle) (text : @& String) (value minValue maxValue : UInt32) (editMode : Bool) : BaseIO (Bool × UInt32)

/-- Value Box control, updates input text wth numbers -/
@[extern "lean_raygui__GuiValueBox"]
opaque valueBox (bounds : @& Rectangle) (text : @& String) (value minValue maxValue : UInt32) (editMode : Bool) : BaseIO (Bool × UInt32)

/-- Text Box control, updates input text -/
@[extern "lean_raygui__GuiTextBox"]
opaque textBox (bounds : @& Rectangle) (text : @& String) (textSize : UInt32) (editMode : Bool) : BaseIO (Bool × String)


/-- Slider control, returns selected value -/
@[extern "lean_raygui__GuiSlider"]
opaque slider (bounds : @& Rectangle) (textLeft : @& String) (textRight : @& String) (value minValue maxValue : Float32) : BaseIO Float32

/-- Slider Bar control, returns selected value -/
@[extern "lean_raygui__GuiSliderBar"]
opaque sliderBar (bounds : @& Rectangle) (textLeft : @& String) (textRight : @& String) (value minValue maxValue : Float32) : BaseIO Float32

/-- Progress Bar control, shows current progress value -/
@[extern "lean_raygui__GuiProgressBar"]
opaque progressBar (bounds : @& Rectangle) (textLeft : @& String) (textRight : @& String) (value minValue maxValue : Float32) : BaseIO Float32

/-- Status Bar control, shows info text -/
@[extern "lean_raygui__GuiStatusBar"]
opaque statusBar (bounds : @& Rectangle) (text : @& String) : BaseIO Unit

/-- Dummy control for placeholders -/
@[extern "lean_raygui__GuiDummyRec"]
opaque dummyRec (bounds : @& Rectangle) (text : @& String) : BaseIO Unit

/-- Grid control, returns mouse cell position -/
@[extern "lean_raygui__GuiGrid"]
opaque grid (bounds : @& Rectangle) (text : @& String) (spacing : Float32) (subdivs : UInt32) (mouseCell : Vector2) : BaseIO Vector2


/-! ### Advance controls set -/

/-- List View control, returns selected list item index -/
@[extern "lean_raygui__GuiListView"]
opaque listView (bounds : @& Rectangle) (text : @& String) (scrollIndex active : UInt32) : BaseIO (UInt32 × UInt32)

/-- List View with extended parameters -/
@[extern "lean_raygui__GuiListViewEx"]
opaque listViewEx (bounds : @& Rectangle) (text : @& Array String) (scrollIndex active focus : UInt32) : BaseIO (UInt32 × UInt32 × UInt32)

/-- Message Box control, displays a message -/
@[extern "lean_raygui__GuiMessageBox"]
opaque messageBox (bounds : @& Rectangle) (title message buttons : @& String) : BaseIO (Option UInt32)

/-- Text Input Box control, ask for text, supports secret -/
@[extern "lean_raygui__GuiTextInputBox"]
opaque textInputBox (bounds : @& Rectangle) (title message buttons text : @& String) (textMaxSize : UInt32) (secretViewActive : Bool) : BaseIO (Option UInt32 × String × Bool)

/-- Color Picker control (multiple color controls) -/
@[extern "lean_raygui__GuiColorPicker"]
opaque colorPicker (bounds : @& Rectangle) (text : @& String) (color : Color) : BaseIO Color

/-- Color Panel control -/
@[extern "lean_raygui__GuiColorPanel"]
opaque colorPanel (bounds : @& Rectangle) (text : @& String) (color : Color) : BaseIO Color

/-- Color Bar Alpha control -/
@[extern "lean_raygui__GuiColorBarAlpha"]
opaque colorBarAlpha (bounds : @& Rectangle) (text : @& String) (alpha : Float32) : BaseIO Float32

/-- Color Bar Hue control -/
@[extern "lean_raygui__GuiColorBarHue"]
opaque colorBarHue (bounds : @& Rectangle) (text : @& String) (value : Float32) : BaseIO Float32

/-- Color Picker control that avoids conversion to RGB on each call (multiple color controls) -/
@[extern "lean_raygui__GuiColorPickerHSV"]
opaque colorPickerHsv (bounds : @& Rectangle) (text : @& String) (colorHsv : Vector3) : BaseIO Vector3

/-- Color Panel control that returns HSV color value, used by `colorPickerHsv` -/
@[extern "lean_raygui__GuiColorPanelHSV"]
opaque colorPanelHsv (bounds : @& Rectangle) (text : @& String) (colorHsv : Vector3) : BaseIO Vector3
