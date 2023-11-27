#pragma once

#include <string>
#include <iostream>
#include <map>

class Wordlist {
public:

    Wordlist();
    ~Wordlist();

    /*
     void setNodeValues(nodekey, nodevalue);

     nodekey getKey();

     
     nodevalue getValue();





     template<typename ValueType>
     void setValue(ValueType newValue)
     {
         value_ = newValue;
     }


     template<typename preferredtype>
     preferredtype getValue()
     {
         if (std::holds_alternative<preferredtype>(value_))
             return std::get<preferredtype>(value_);
         else
             return getCastedValue<preferredtype>();
     }

     template<>
     std::string getValue()
     {
         switch (value_.index())
         {
         case 0:
             return std::to_string(std::get<int>(value_));
         case 1:
             return std::to_string(std::get<float>(value_));
         case 2:
             return std::get<std::string>(value_);
         case 3:
             return std::to_string(std::get<double>(value_));
         case 4:
             return std::to_string(std::get<bool>(value_));
         default:
             return std::to_string(std::get<bool>(value_));
         }
     }

     template<typename preferredtype>
     preferredtype getCastedValue()
     {
         switch (value_.index())
         {
         case 0:
             return static_cast<preferredtype>(std::get<int>(value_));
         case 1:
             return static_cast<preferredtype>(std::get<float>(value_));
             break;
         case 2:
             return static_cast<preferredtype>(std::get<double>(value_));
         case 3:
                 return 1;
         default:
                 int i = 1;
             //throw std::exception("Type not supported");
         }
     }
     
 private:

     nodekey    key_;
     nodevalue value_;
     
     */
    
    
};
