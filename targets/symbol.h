// $Id: symbol.h,v 1.1 2015/02/21 20:27:35 ist13500 Exp $ -*- c++ -*-
#ifndef __PWN_SEMANTICS_SYMBOL_H__
#define __PWN_SEMANTICS_SYMBOL_H__

#include <string>
#include <cdk/basic_type.h>

namespace pwn {

    class symbol {
      basic_type *_type;
      std::string _name;
      long _value; // hack!
      int _offset;

    public:
      inline symbol( basic_type *type, const std::string &name, long value) :
          _type(type), _name(name), _value(value) {
      }

      virtual ~symbol() {
        delete _type;
      }

      inline basic_type *type() const {
        return _type;
      }
      inline const std::string &name() const {
        return _name;
      }
      inline long value() const {
        return _value;
      }
      inline long value(long v) {
        return _value = v;
      }
      inline int offset(int offset) {
				return _offset = offset;
			}
			inline int offset() {
				return _offset;
			}
      
    };

} // pwn

#endif
