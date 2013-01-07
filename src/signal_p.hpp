#pragma once
/*
**  Copyright (C) 2012 Aldebaran Robotics
**  See COPYING for the license
*/

#ifndef _SRC_SIGNAL_P_HPP_
#define _SRC_SIGNAL_P_HPP_

#include <qitype/signal.hpp>
#include <boost/thread/thread.hpp>
#include <boost/thread/recursive_mutex.hpp>

namespace qi {

  typedef std::map<SignalBase::Link, SignalSubscriberPtr> SignalSubscriberMap;

  class SignalBasePrivate
  {
  public:
    bool disconnect(const SignalBase::Link& l);
    bool reset();

  public:
    SignalSubscriberMap            subscriberMap;
    std::string                    signature;
    boost::recursive_mutex         mutex;
    MetaCallType                   defaultCallType;
  };

}

#endif  // _SRC_SIGNAL_P_HPP_
