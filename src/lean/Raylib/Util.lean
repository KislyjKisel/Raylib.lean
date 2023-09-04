namespace Raylib

instance {α} {β} [h1 : Nonempty α] [h2 : Nonempty β] : Nonempty (α × β) :=
  Nonempty.intro (Classical.choice h1, Classical.choice h2)

end Raylib
