// Copyright 2010, Google Inc.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Google Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef MOZC_DICTIONARY_DICTIONARY_INTERFACE_H_
#define MOZC_DICTIONARY_DICTIONARY_INTERFACE_H_

namespace mozc {

// These structures are defined in converter
struct Node;
class NodeAllocatorInterface;

class DictionaryInterface {
 public:
  virtual Node *LookupPredictive(const char *str, int size,
                                 NodeAllocatorInterface *allocator) const = 0;

  virtual Node *LookupPrefix(const char *str, int size,
                             NodeAllocatorInterface *allocator) const = 0;

  // For reverse lookup, the reading is stored in Node::value and the word
  // is stored in Node::key.
  virtual Node *LookupReverse(const char *str, int size,
                              NodeAllocatorInterface *allocator) const = 0;

 protected:
  // Do not allow instantiation/destruction
  DictionaryInterface() {}
  virtual ~DictionaryInterface() {}
};

class DictionaryFactory {
 public:
  // return singleton object
  static DictionaryInterface *GetDictionary();

  // dependency injection for unittesting
  static void SetDictionary(DictionaryInterface *dictionary);

 private:
  DictionaryFactory() {}
  ~DictionaryFactory() {}
};
} // namespace mozc

#endif  // MOZC_DICTIONARY_INTERFACE_H_
