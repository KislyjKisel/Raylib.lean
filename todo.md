* Flat external objects for FFI.
  Change
  `lean_object { .., -> Image { ..header, -> data } }`
  to
  `lean_object { .., -> BoxedImage { ..header, ..data } }`
                                  data ptr = ^ = this + sizeof(Header)
  (benchmark!)

* Binary data retrieval from images, audio etc
  (opaque readonly buffer type? mb smth like a trait object)

* Optional usage of lean's alloc

* Define PODs in Lean instead of using "external" objects

* Debug configuration options
