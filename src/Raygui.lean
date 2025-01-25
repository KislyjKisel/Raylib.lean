import Pod.Float
import Raymath.Core
import Raylib.Structures

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

def IconName : Type := UInt8
def IconName.none : UInt8 := 0
def IconName.folderFileOpen : UInt8 := 1
def IconName.fileSaveClassic : UInt8 := 2
def IconName.folderOpen : UInt8 := 3
def IconName.folderSave : UInt8 := 4
def IconName.fileOpen : UInt8 := 5
def IconName.fileSave : UInt8 := 6
def IconName.fileExport : UInt8 := 7
def IconName.fileAdd : UInt8 := 8
def IconName.fileDelete : UInt8 := 9
def IconName.filetypeText : UInt8 := 10
def IconName.filetypeAudio : UInt8 := 11
def IconName.filetypeImage : UInt8 := 12
def IconName.filetypePlay : UInt8 := 13
def IconName.filetypeVideo : UInt8 := 14
def IconName.filetypeInfo : UInt8 := 15
def IconName.fileCopy : UInt8 := 16
def IconName.fileCut : UInt8 := 17
def IconName.filePaste : UInt8 := 18
def IconName.cursorHand : UInt8 := 19
def IconName.cursorPointer : UInt8 := 20
def IconName.cursorClassic : UInt8 := 21
def IconName.pencil : UInt8 := 22
def IconName.pencilBig : UInt8 := 23
def IconName.brushClassic : UInt8 := 24
def IconName.brushPainter : UInt8 := 25
def IconName.waterDrop : UInt8 := 26
def IconName.colorPicker : UInt8 := 27
def IconName.rubber : UInt8 := 28
def IconName.colorBucket : UInt8 := 29
def IconName.textT : UInt8 := 30
def IconName.textA : UInt8 := 31
def IconName.scale : UInt8 := 32
def IconName.resize : UInt8 := 33
def IconName.filterPoint : UInt8 := 34
def IconName.filterBilinear : UInt8 := 35
def IconName.crop : UInt8 := 36
def IconName.cropAlpha : UInt8 := 37
def IconName.squareToggle : UInt8 := 38
def IconName.symmetry : UInt8 := 39
def IconName.symmetryHorizontal : UInt8 := 40
def IconName.symmetryVertical : UInt8 := 41
def IconName.lens : UInt8 := 42
def IconName.lensBig : UInt8 := 43
def IconName.eyeOn : UInt8 := 44
def IconName.eyeOff : UInt8 := 45
def IconName.filterTop : UInt8 := 46
def IconName.filter : UInt8 := 47
def IconName.targetPoint : UInt8 := 48
def IconName.targetSmall : UInt8 := 49
def IconName.targetBig : UInt8 := 50
def IconName.targetMove : UInt8 := 51
def IconName.cursorMove : UInt8 := 52
def IconName.cursorScale : UInt8 := 53
def IconName.cursorScaleRight : UInt8 := 54
def IconName.cursorScaleLeft : UInt8 := 55
def IconName.undo : UInt8 := 56
def IconName.redo : UInt8 := 57
def IconName.reredo : UInt8 := 58
def IconName.mutate : UInt8 := 59
def IconName.rotate : UInt8 := 60
def IconName.repeat : UInt8 := 61
def IconName.shuffle : UInt8 := 62
def IconName.emptybox : UInt8 := 63
def IconName.target : UInt8 := 64
def IconName.targetSmallFill : UInt8 := 65
def IconName.targetBigFill : UInt8 := 66
def IconName.targetMoveFill : UInt8 := 67
def IconName.cursorMoveFill : UInt8 := 68
def IconName.cursorScaleFill : UInt8 := 69
def IconName.cursorScaleRightFill : UInt8 := 70
def IconName.cursorScaleLeftFill : UInt8 := 71
def IconName.undoFill : UInt8 := 72
def IconName.redoFill : UInt8 := 73
def IconName.reredoFill : UInt8 := 74
def IconName.mutateFill : UInt8 := 75
def IconName.rotateFill : UInt8 := 76
def IconName.repeatFill : UInt8 := 77
def IconName.shuffleFill : UInt8 := 78
def IconName.emptyboxSmall : UInt8 := 79
def IconName.box : UInt8 := 80
def IconName.boxTop : UInt8 := 81
def IconName.boxTopRight : UInt8 := 82
def IconName.boxRight : UInt8 := 83
def IconName.boxBottomRight : UInt8 := 84
def IconName.boxBottom : UInt8 := 85
def IconName.boxBottomLeft : UInt8 := 86
def IconName.boxLeft : UInt8 := 87
def IconName.boxTopLeft : UInt8 := 88
def IconName.boxCenter : UInt8 := 89
def IconName.boxCircleMask : UInt8 := 90
def IconName.pot : UInt8 := 91
def IconName.alphaMultiply : UInt8 := 92
def IconName.alphaClear : UInt8 := 93
def IconName.dithering : UInt8 := 94
def IconName.mipmaps : UInt8 := 95
def IconName.boxGrid : UInt8 := 96
def IconName.grid : UInt8 := 97
def IconName.boxCornersSmall : UInt8 := 98
def IconName.boxCornersBig : UInt8 := 99
def IconName.fourBoxes : UInt8 := 100
def IconName.gridFill : UInt8 := 101
def IconName.boxMultisize : UInt8 := 102
def IconName.zoomSmall : UInt8 := 103
def IconName.zoomMedium : UInt8 := 104
def IconName.zoomBig : UInt8 := 105
def IconName.zoomAll : UInt8 := 106
def IconName.zoomCenter : UInt8 := 107
def IconName.boxDotsSmall : UInt8 := 108
def IconName.boxDotsBig : UInt8 := 109
def IconName.boxConcentric : UInt8 := 110
def IconName.boxGridBig : UInt8 := 111
def IconName.okTick : UInt8 := 112
def IconName.cross : UInt8 := 113
def IconName.arrowLeft : UInt8 := 114
def IconName.arrowRight : UInt8 := 115
def IconName.arrowDown : UInt8 := 116
def IconName.arrowUp : UInt8 := 117
def IconName.arrowLeftFill : UInt8 := 118
def IconName.arrowRightFill : UInt8 := 119
def IconName.arrowDownFill : UInt8 := 120
def IconName.arrowUpFill : UInt8 := 121
def IconName.audio : UInt8 := 122
def IconName.fx : UInt8 := 123
def IconName.wave : UInt8 := 124
def IconName.waveSinus : UInt8 := 125
def IconName.waveSquare : UInt8 := 126
def IconName.waveTriangular : UInt8 := 127
def IconName.crossSmall : UInt8 := 128
def IconName.playerPrevious : UInt8 := 129
def IconName.playerPlayBack : UInt8 := 130
def IconName.playerPlay : UInt8 := 131
def IconName.playerPause : UInt8 := 132
def IconName.playerStop : UInt8 := 133
def IconName.playerNext : UInt8 := 134
def IconName.playerRecord : UInt8 := 135
def IconName.magnet : UInt8 := 136
def IconName.lockClose : UInt8 := 137
def IconName.lockOpen : UInt8 := 138
def IconName.clock : UInt8 := 139
def IconName.tools : UInt8 := 140
def IconName.gear : UInt8 := 141
def IconName.gearBig : UInt8 := 142
def IconName.bin : UInt8 := 143
def IconName.handPointer : UInt8 := 144
def IconName.laser : UInt8 := 145
def IconName.coin : UInt8 := 146
def IconName.explosion : UInt8 := 147
def IconName.«1up» : UInt8 := 148
def IconName.player : UInt8 := 149
def IconName.playerJump : UInt8 := 150
def IconName.key : UInt8 := 151
def IconName.demon : UInt8 := 152
def IconName.textPopup : UInt8 := 153
def IconName.gearEx : UInt8 := 154
def IconName.crack : UInt8 := 155
def IconName.crackPoints : UInt8 := 156
def IconName.star : UInt8 := 157
def IconName.door : UInt8 := 158
def IconName.exit : UInt8 := 159
def IconName.mode2d : UInt8 := 160
def IconName.mode3d : UInt8 := 161
def IconName.cube : UInt8 := 162
def IconName.cubeFaceTop : UInt8 := 163
def IconName.cubeFaceLeft : UInt8 := 164
def IconName.cubeFaceFront : UInt8 := 165
def IconName.cubeFaceBottom : UInt8 := 166
def IconName.cubeFaceRight : UInt8 := 167
def IconName.cubeFaceBack : UInt8 := 168
def IconName.camera : UInt8 := 169
def IconName.special : UInt8 := 170
def IconName.linkNet : UInt8 := 171
def IconName.linkBoxes : UInt8 := 172
def IconName.linkMulti : UInt8 := 173
def IconName.link : UInt8 := 174
def IconName.linkBroke : UInt8 := 175
def IconName.textNotes : UInt8 := 176
def IconName.notebook : UInt8 := 177
def IconName.suitcase : UInt8 := 178
def IconName.suitcaseZip : UInt8 := 179
def IconName.mailbox : UInt8 := 180
def IconName.monitor : UInt8 := 181
def IconName.printer : UInt8 := 182
def IconName.photoCamera : UInt8 := 183
def IconName.photoCameraFlash : UInt8 := 184
def IconName.house : UInt8 := 185
def IconName.heart : UInt8 := 186
def IconName.corner : UInt8 := 187
def IconName.verticalBars : UInt8 := 188
def IconName.verticalBarsFill : UInt8 := 189
def IconName.lifeBars : UInt8 := 190
def IconName.info : UInt8 := 191
def IconName.crossline : UInt8 := 192
def IconName.help : UInt8 := 193
def IconName.filetypeAlpha : UInt8 := 194
def IconName.filetypeHome : UInt8 := 195
def IconName.layersVisible : UInt8 := 196
def IconName.layers : UInt8 := 197
def IconName.window : UInt8 := 198
def IconName.hidpi : UInt8 := 199
def IconName.filetypeBinary : UInt8 := 200
def IconName.hex : UInt8 := 201
def IconName.shield : UInt8 := 202
def IconName.fileNew : UInt8 := 203
def IconName.folderAdd : UInt8 := 204
def IconName.alarm : UInt8 := 205
def IconName.cpu : UInt8 := 206
def IconName.rom : UInt8 := 207
def IconName.stepOver : UInt8 := 208
def IconName.stepInto : UInt8 := 209
def IconName.stepOut : UInt8 := 210
def IconName.restart : UInt8 := 211
def IconName.breakpointOn : UInt8 := 212
def IconName.breakpointOff : UInt8 := 213
def IconName.burgerMenu : UInt8 := 214
def IconName.caseSensitive : UInt8 := 215
def IconName.regExp : UInt8 := 216
def IconName.folder : UInt8 := 217
def IconName.file : UInt8 := 218
def IconName.sandTimer : UInt8 := 219

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

/--
Get gui custom font (global state).
(todo: check if gui font may be unloaded more than once)
-/
@[extern "lean_raygui__GuiGetFont"]
opaque getFont (ctx : Raylib.Context) : BaseIO Raylib.Font

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

/--
Combo Box control, returns selected item index.
NOTE: There is a `text` size limit (truncated) and maximum number of variants
(see Raygui source/compilation flags, by default RAYGUI_TEXTSPLIT_MAX_ITEMS=128, RAYGUI_TEXTSPLIT_MAX_TEXT_SIZE=1024).
-/
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

/--
Text Box control, updates input text.
`textSize` - max length.
NOTE: Returns true on ENTER pressed (useful for data validation).
-/
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

/--
List View control, returns selected list item index.
NOTE: There is a `text` size limit (truncated) and maximum number of variants
(see Raygui source/compilation flags, by default RAYGUI_TEXTSPLIT_MAX_ITEMS=128, RAYGUI_TEXTSPLIT_MAX_TEXT_SIZE=1024).
-/
@[extern "lean_raygui__GuiListView"]
opaque listView (bounds : @& Rectangle) (text : @& String) (scrollIndex active : UInt32) : BaseIO (UInt32 × UInt32)

/-- List View with extended parameters (without a size limit). -/
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
