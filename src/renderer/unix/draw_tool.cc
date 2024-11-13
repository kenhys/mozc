// Copyright 2010-2021, Google Inc.
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

#include "renderer/unix/draw_tool.h"

#include <cstdint>

#include "base/coordinates.h"
#include "renderer/unix/cairo_wrapper.h"
#include "renderer/unix/const.h"

namespace mozc {
namespace renderer {
namespace gtk {

void DrawTool::Save() { cairo_->Save(); }

void DrawTool::Restore() { cairo_->Restore(); }

void DrawTool::Reset(CairoWrapperInterface *cairo) { cairo_.reset(cairo); }

void DrawTool::SetColor(const RGBA &color) {
  cairo_->SetSourceRGBA(static_cast<double>(color.red) / 255.0,
                        static_cast<double>(color.green) / 255.0,
                        static_cast<double>(color.blue) / 255.0,
                        static_cast<double>(color.alpha) / 255.0);
}

void DrawTool::FillRect(const Rect &rect, const RGBA &color) {
  SetColor(color);
  cairo_->Rectangle(rect.origin.x, rect.origin.y, rect.size.width,
                    rect.size.height);
  cairo_->Fill();
}

void DrawTool::FrameRect(const Rect &rect, const RGBA &color,
                         const uint32_t line_width) {
  SetColor(color);
  cairo_->SetLineWidth(static_cast<double>(line_width));
  cairo_->Rectangle(rect.origin.x, rect.origin.y, rect.size.width,
                    rect.size.height);
  cairo_->Stroke();
}

void DrawTool::DrawLine(const Point &from, const Point &to, const RGBA &color,
                        const uint32_t line_width) {
  SetColor(color);
  cairo_->SetLineWidth(static_cast<double>(line_width));
  cairo_->MoveTo(from.x, from.y);
  cairo_->LineTo(to.x, to.y);
  cairo_->Stroke();
}

}  // namespace gtk
}  // namespace renderer
}  // namespace mozc