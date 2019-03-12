#include "uFR.h"
#include "ufr-lib/include/uFCoder.h"
#include <string>
#include <string.h>
#include <cstring>
#include <sstream>

std::string UFR::GetDlTypeName(uint8_t dl_type_code) {

	switch (dl_type_code) {
	case DL_MIFARE_ULTRALIGHT:
		return "DL_MIFARE_ULTRALIGHT";
	case DL_MIFARE_ULTRALIGHT_EV1_11:
		return "DL_MIFARE_ULTRALIGHT_EV1_11";
	case DL_MIFARE_ULTRALIGHT_EV1_21:
		return "DL_MIFARE_ULTRALIGHT_EV1_21";
	case DL_MIFARE_ULTRALIGHT_C:
		return "DL_MIFARE_ULTRALIGHT_C";
	case DL_NTAG_203:
		return "DL_NTAG_203";
	case DL_NTAG_210:
		return "DL_NTAG_210";
	case DL_NTAG_212:
		return "DL_NTAG_212";
	case DL_NTAG_213:
		return "DL_NTAG_213";
	case DL_NTAG_215:
		return "DL_NTAG_215";
	case DL_NTAG_216:
		return "DL_NTAG_216";
	case DL_MIKRON_MIK640D:
		return "DL_MIKRON_MIK640D";
	case DL_MIFARE_MINI:
		return "DL_MIFARE_MINI";
	case DL_MIFARE_CLASSIC_1K:
		return "DL_MIFARE_CLASSIC_1K";
	case DL_MIFARE_CLASSIC_4K:
		return "DL_MIFARE_CLASSIC_4K";
	case DL_MIFARE_PLUS_S_2K_SL0:
		return "DL_MIFARE_PLUS_S_2K_SL0";
	case DL_MIFARE_PLUS_S_4K_SL0:
		return "DL_MIFARE_PLUS_S_4K_SL0";
	case DL_MIFARE_PLUS_X_2K_SL0:
		return "DL_MIFARE_PLUS_X_2K_SL0";
	case DL_MIFARE_PLUS_X_4K_SL0:
		return "DL_MIFARE_PLUS_X_4K_SL0";
	case DL_MIFARE_DESFIRE:
		return "DL_MIFARE_DESFIRE";
	case DL_MIFARE_DESFIRE_EV1_2K:
		return "DL_MIFARE_DESFIRE_EV1_2K";
	case DL_MIFARE_DESFIRE_EV1_4K:
		return "DL_MIFARE_DESFIRE_EV1_4K";
	case DL_MIFARE_DESFIRE_EV1_8K:
		return "DL_MIFARE_DESFIRE_EV1_8K";
	case DL_MIFARE_DESFIRE_EV2_2K:
		return "DL_MIFARE_DESFIRE_EV2_2K";
	case DL_MIFARE_DESFIRE_EV2_4K:
		return "DL_MIFARE_DESFIRE_EV2_4K";
	case DL_MIFARE_DESFIRE_EV2_8K:
		return "DL_MIFARE_DESFIRE_EV2_8K";
	case DL_MIFARE_PLUS_S_2K_SL1:
		return "DL_MIFARE_PLUS_S_2K_SL1";
	case DL_MIFARE_PLUS_X_2K_SL1:
		return "DL_MIFARE_PLUS_X_2K_SL1";
	case DL_MIFARE_PLUS_EV1_2K_SL1:
		return "DL_MIFARE_PLUS_EV1_2K_SL1";
	case DL_MIFARE_PLUS_X_2K_SL2:
		return "DL_MIFARE_PLUS_X_2K_SL2";
	case DL_MIFARE_PLUS_S_2K_SL3:
		return "DL_MIFARE_PLUS_S_2K_SL3";
	case DL_MIFARE_PLUS_X_2K_SL3:
		return "DL_MIFARE_PLUS_X_2K_SL3";
	case DL_MIFARE_PLUS_EV1_2K_SL3:
		return "DL_MIFARE_PLUS_EV1_2K_SL3";
	case DL_MIFARE_PLUS_S_4K_SL1:
		return "DL_MIFARE_PLUS_S_4K_SL1";
	case DL_MIFARE_PLUS_X_4K_SL1:
		return "DL_MIFARE_PLUS_X_4K_SL1";
	case DL_MIFARE_PLUS_EV1_4K_SL1:
		return "DL_MIFARE_PLUS_EV1_4K_SL1";
	case DL_MIFARE_PLUS_X_4K_SL2:
		return "DL_MIFARE_PLUS_X_4K_SL2";
	case DL_MIFARE_PLUS_S_4K_SL3:
		return "DL_MIFARE_PLUS_S_4K_SL3";
	case DL_MIFARE_PLUS_X_4K_SL3:
		return "DL_MIFARE_PLUS_X_4K_SL3";
	case DL_MIFARE_PLUS_EV1_4K_SL3:
		return "DL_MIFARE_PLUS_EV1_4K_SL3";
	case DL_GENERIC_ISO14443_4:
		return "DL_GENERIC_ISO_14443_4";
	case DL_GENERIC_ISO14443_4_TYPE_B:
		return "DL_GENERIC_ISO14443_4_TYPE_B";
	case DL_GENERIC_ISO14443_3_TYPE_B:
		return "DL_GENERIC_ISO14443_3_TYPE_B";
	case DL_IMEI_UID:
		return "DL_IMEI_UID";
	}
	return "UNKNOWN CARD";
}

std::string UFR::ConvertUint8ArrayToStr(uint8_t *arr, uint32_t length, std::string delimiter){

    char hex[4];
    std::string uidStr = "";

    for(uint32_t i = 0; i < length; i++){
        strcpy(hex, "");
        sprintf(hex, "%02X", arr[i]);
        uidStr += hex;
    }

    for(uint32_t i = 0; i < uidStr.length(); i++){

        i = i + 2;
        uidStr.insert(i, delimiter);
    }

    uidStr = uidStr.substr(0, uidStr.length() - 1);

    return uidStr;
}

void UFR::ConvertToUint8Array(std::string str, uint8_t *array) {

    for (unsigned int i = 0; i < str.length() / 2; i++) {

        std::string part = str.substr(i * 2, 2);

            char str1[32];
            char *ptr;
            strcpy(str1, part.c_str());

        array[i] = strtol(str1, &ptr, 16);

    }

}
