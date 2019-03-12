#include <string>
#include <string.h>
#include <cstring>
#include <sstream>

class UFR{

    public:

    std::string GetDlTypeName(uint8_t dl_type_code);
    std::string ConvertUint8ArrayToStr(uint8_t *arr, uint32_t length, std::string delimiter);
    std::string byte_2_str(char *bytes, int size, std::string delimiter);
    void ConvertToUint8Array(std::string str, uint8_t *array);

};
