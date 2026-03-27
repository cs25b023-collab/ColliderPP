#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

class Any{
private:
    std::string type;
    union {
        int ivalue;
        float fvalue;
        std::string* svalue;
        std::vector<Any>* lvalues;
        std::unordered_map<std::string,Any>* mvalues;
    } data;

    void check_error(const std::string& target) const {
        if(target!=type){
            std::cerr << "Using "<<type<<" as "<<target<<"\n";
        }
    }

public:
    Any(int a) {
        type = "int";
        data.ivalue = a;
    }

    Any(float a) {
        type = "float";
        data.fvalue = a;
    }

    Any(const std::string &a) {
        type = "string";
        data.svalue = new std::string(a);
    }

    Any(const std::vector<Any> a) {
        type = "list";
        data.lvalues = new std::vector(a);
    }

    Any(std::unordered_map<std::string, Any> a) {
        type = "dict";
        data.mvalues = new std::unordered_map(a);
    }

    ~Any () {
        if (type == "string") delete data.svalue;
        if (type == "list") delete data.lvalues;
        if (type == "dict") delete data.mvalues; 
    }

    operator int() const {
        check_error("int");
        return data.ivalue;
    }

    operator float() const {
        check_error("float");
        return data.fvalue;
    }

    operator std::string() const {
        check_error("string");
        return *data.svalue;
    }

    const Any& operator[](int idx) const {
        std::cout<<"1\n";
        check_error("list");
        return data.lvalues->at(idx);
    }
    const Any& operator[](const std::string key) const {
        check_error("dict");
        return data.mvalues->at(key);
    }
    
};