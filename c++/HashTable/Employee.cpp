//
// Created by moonmaster on 2/9/16.
//

#include "Employee.h"

const std::string & Employee::getName ( ) const
{ return name; };

bool Employee::operator==( const Employee & rhs ) const
{return getName( ) == rhs.getName( );};

bool Employee::operator!=( const Employee & rhs ) const
{ return !( *this == rhs ); };

const std::string Employee::hashed() const
{
   return hash;
};