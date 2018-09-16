#include <pberror.h>

void pb_raise_pbio_error(pbio_error_t error){
    switch(error){
        case PBIO_SUCCESS:
            break;
        case PBIO_ERROR_FAILED:
            mp_raise_msg(&mp_type_RuntimeError, "Unknown error");
            break;
        case PBIO_ERROR_INVALID_ARG:
            mp_raise_ValueError("Invalid argument");
            break;            
        case PBIO_ERROR_INVALID_PORT:
            mp_raise_ValueError("Invalid port");
            break;
        case PBIO_ERROR_IO:
            mp_raise_msg(&mp_type_OSError, "I/O error");
            break;
        case PBIO_ERROR_NO_DEV:
            mp_raise_ValueError("Device is not connected");
            break;
        default:
            mp_raise_msg(&mp_type_RuntimeError, "Unknown error");
            break;
    }  
}