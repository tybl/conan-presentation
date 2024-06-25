#!/usr/bin/sh
podman --root=$TMPDIR/containers run -it --rm -v $PWD:/code conan-presentation bash
