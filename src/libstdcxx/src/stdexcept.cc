// Methods for Exception Support for -*- C++ -*-

// Copyright (C) 1997, 1999, 2001, 2002, 2005 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 2, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License along
// with this library; see the file COPYING.  If not, write to the Free
// Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,
// USA.

// As a special exception, you may use this file as part of a free software
// library without restriction.  Specifically, if other files instantiate
// templates or use macros or inline functions from this file, or you compile
// this file and link it with other files to produce an executable, this
// file does not by itself cause the resulting executable to be covered by
// the GNU General Public License.  This exception does not however
// invalidate any other reasons why the executable file might be covered by
// the GNU General Public License.

//
// ISO C++ 14882: 19.1  Exception classes
//

#include <string>
#include <stdexcept>
#include <cxxabi.h>

_GLIBCXX_BEGIN_NAMESPACE(std)

  logic_error::logic_error(const string& __arg) 
  : exception(), _M_msg(__arg) { }

#ifndef _LIBCPPABI_VERSION
  logic_error::~logic_error() throw() { }

  const char*
  logic_error::what() const throw()
  { return _M_msg.c_str(); }
#endif  // _LIBCPPABI_VERSION

  domain_error::domain_error(const string& __arg)
  : logic_error(__arg) { }

  invalid_argument::invalid_argument(const string& __arg)
  : logic_error(__arg) { }

  length_error::length_error(const string& __arg)
  : logic_error(__arg) { }

  out_of_range::out_of_range(const string& __arg)
  : logic_error(__arg) { }

  runtime_error::runtime_error(const string& __arg) 
  : exception(), _M_msg(__arg) { }

#ifndef _LIBCPPABI_VERSION
  runtime_error::~runtime_error() throw() { }

  const char*
  runtime_error::what() const throw()
  { return _M_msg.c_str(); }
#endif  // _LIBCPPABI_VERSION

  range_error::range_error(const string& __arg)
  : runtime_error(__arg) { }

  overflow_error::overflow_error(const string& __arg)
  : runtime_error(__arg) { }

  underflow_error::underflow_error(const string& __arg)
  : runtime_error(__arg) { }

_GLIBCXX_END_NAMESPACE

