class Any{
private:
    std::string type;
    union {
        int ivalue;
        float fvalue;
        std::string svalue;
        std::vector<Any> lvalues;
        std::unordered_map<std::string,Any> mvalues;
    } data;

public:
    operator int() const {
        if(type!="int"){
            std::cerr << "Using "<<type<<" as int\n";
            return 0;
        }
        return data.ivalue;
    }
};