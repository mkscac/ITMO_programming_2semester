# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/mac/CLionProjects/prg_9laba_REST_(curl)/cmake-build-debug/_deps/curl-src"
  "/Users/mac/CLionProjects/prg_9laba_REST_(curl)/cmake-build-debug/_deps/curl-build"
  "/Users/mac/CLionProjects/prg_9laba_REST_(curl)/cmake-build-debug/_deps/curl-subbuild/curl-populate-prefix"
  "/Users/mac/CLionProjects/prg_9laba_REST_(curl)/cmake-build-debug/_deps/curl-subbuild/curl-populate-prefix/tmp"
  "/Users/mac/CLionProjects/prg_9laba_REST_(curl)/cmake-build-debug/_deps/curl-subbuild/curl-populate-prefix/src/curl-populate-stamp"
  "/Users/mac/CLionProjects/prg_9laba_REST_(curl)/cmake-build-debug/_deps/curl-subbuild/curl-populate-prefix/src"
  "/Users/mac/CLionProjects/prg_9laba_REST_(curl)/cmake-build-debug/_deps/curl-subbuild/curl-populate-prefix/src/curl-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/mac/CLionProjects/prg_9laba_REST_(curl)/cmake-build-debug/_deps/curl-subbuild/curl-populate-prefix/src/curl-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/mac/CLionProjects/prg_9laba_REST_(curl)/cmake-build-debug/_deps/curl-subbuild/curl-populate-prefix/src/curl-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
