/*
 * Copyright (c) 2012 Aldebaran Robotics. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the COPYING file.
 */

#pragma once

#ifndef _LIBQI_QI_ATOMIC_HPP_
#define _LIBQI_QI_ATOMIC_HPP_

#ifdef _MSC_VER
# include <windows.h>
# pragma intrinsic(_InterlockedIncrement16)
# pragma intrinsic(_InterlockedDecrement16)
# pragma intrinsic(_InterlockedIncrement)
# pragma intrinsic(_InterlockedDecrement)

extern "C" short __cdecl _InterlockedIncrement16(short volatile *);
extern "C" short __cdecl _InterlockedDecrement16(short volatile *);
extern "C" long __cdecl _InterlockedIncrement(long volatile *);
extern "C" long __cdecl _InterlockedDecrement(long volatile *);
/*
 * No extern with 64, it seems that intrinsic version of these
 * functions are not always avaiblables
 */
#endif

#include <qi/config.hpp>

namespace qi
{
  template <typename T>
  class Atomic
  {
  public:
    Atomic()
      : _value(0)
    {
    }

    Atomic(T value)
      : _value(value)
    {
    }

    /* prefix operators */
    T operator++();
    T operator--();

    T operator*()
    {
      return _value;
    }

  private:
    T _value;
  };

#ifdef __GNUC__
    template <typename T>
    T Atomic<T>::operator++()
    {
      return __sync_add_and_fetch(&_value, 1);
    }

    template <typename T>
    T Atomic<T>::operator--()
    {
      return __sync_sub_and_fetch(&_value, 1);
    }
#endif

#ifdef _MSC_VER

  template<>
  inline short Atomic<short>::operator++()
  {
    return _InterlockedIncrement16(&_value);
  }

  template<>
  inline short Atomic<short>::operator--()
  {
    return _InterlockedDecrement16(&_value);
  }

  template<>
  inline unsigned short Atomic<unsigned short>::operator++()
  {
    return _InterlockedIncrement16(reinterpret_cast<short*>(&_value));
  }

  template<>
  inline unsigned short Atomic<unsigned short>::operator--()
  {
    return _InterlockedDecrement16(reinterpret_cast<short*>(&_value));
  }

  template <>
  inline long Atomic<long>::operator++()
  {
    return _InterlockedIncrement(&_value);
  }

  template <>
  inline long Atomic<long>::operator--()
  {
    return _InterlockedDecrement(&_value);
  }

  template <>
  inline unsigned long Atomic<unsigned long>::operator++()
  {
    return _InterlockedIncrement(reinterpret_cast<long*>(&_value));
  }

  template <>
  inline unsigned long Atomic<unsigned long>::operator--()
  {
    return _InterlockedDecrement(reinterpret_cast<long*>(&_value));
  }
  template <>
  inline int Atomic<int>::operator++()
  {
    return _InterlockedIncrement(reinterpret_cast<long*>(&_value));
  }

  template <>
  inline int Atomic<int>::operator--()
  {
    return _InterlockedDecrement(reinterpret_cast<long*>(&_value));
  }

  template <>
  inline unsigned int Atomic<unsigned int>::operator++()
  {
    return _InterlockedIncrement(reinterpret_cast<long*>(&_value));
  }

  template <>
  inline unsigned int Atomic<unsigned int>::operator--()
  {
    return _InterlockedDecrement(reinterpret_cast<long*>(&_value));
  }

  template <>
  inline long long Atomic<long long>::operator++()
  {
    return InterlockedIncrement64(&_value);
  }

  template <>
  inline long long Atomic<long long>::operator--()
  {
    return InterlockedDecrement64(&_value);
  }

  template <>
  inline unsigned long long Atomic<unsigned long long>::operator++()
  {
    return InterlockedIncrement64(reinterpret_cast<long long*>(&_value));
  }

  template <>
  inline unsigned long long Atomic<unsigned long long>::operator--()
  {
    return InterlockedDecrement64(reinterpret_cast<long long*>(&_value));
  }

#endif
}

#endif // _LIBQI_QI_ATOMIC_HPP_
