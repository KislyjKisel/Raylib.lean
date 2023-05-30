* Flat external objects for FFI.
  Change
  `lean_object { .., -> Image { ..header, -> data } }`
  to
  `lean_object { .., -> BoxedImage { ..header, ..data } }`
                                  data ptr = ^ = this + sizeof(Header)
  (benchmark!)

* Binary data retrieval from images, audio etc
  (opaque readonly buffer type? mb smth like a trait object)

* Debug configuration options

* ST without result box allocation via custom no-error variant (-> EST, <-> ST)
