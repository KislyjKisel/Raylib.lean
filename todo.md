* Flat external objects for FFI.
  Change
  `lean_object { .., -> Image { ..header, -> data } }`
  to
  `lean_object { .., -> BoxedImage { ..header, ..data } }`
                                  data ptr = ^ = this + sizeof(Header)
  (benchmark!)

* ST without result box allocation via custom no-error variant (-> EST, <-> ST)
  (does ST/IO allocate on every call? is it bad?
  IIRC there was a note somewhere saying that Lean devs want to fix it)

* Separate `extern_lib` for the raylib when interdependent single-package `extern_lib`s will be possible
