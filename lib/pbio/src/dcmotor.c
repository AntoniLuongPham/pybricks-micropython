#include <pbio/dcmotor.h>

pbio_dcmotor_settings_t dcmotor_settings[] = {
    [PORT_TO_IDX(PBDRV_CONFIG_FIRST_MOTOR_PORT) ... PORT_TO_IDX(PBDRV_CONFIG_LAST_MOTOR_PORT)]{
        .direction = PBIO_MOTOR_DIR_NORMAL,
        .max_stall_duty = PBIO_MAX_DUTY
    }
};

pbio_error_t pbio_dcmotor_set_constant_settings(pbio_port_t port, pbio_motor_dir_t direction){
    pbio_error_t status = pbdrv_motor_status(port);
    if (status == PBIO_SUCCESS) {
        dcmotor_settings[PORT_TO_IDX(port)].direction = direction;
    }
    return status;
}

pbio_error_t pbio_dcmotor_set_variable_settings(pbio_port_t port, float_t stall_torque_limit){
    pbio_error_t status = pbdrv_motor_status(port);
    int16_t max_stall_duty = (int16_t) (PBIO_DUTY_PCT_TO_ABS * stall_torque_limit);
    if (max_stall_duty < 0 || max_stall_duty > PBIO_MAX_DUTY) {
        status = PBIO_ERROR_INVALID_ARG;
    }
    if (status == PBIO_SUCCESS) { 
        dcmotor_settings[PORT_TO_IDX(port)].max_stall_duty = max_stall_duty;
    }
    return status;
}

pbio_error_t pbio_dcmotor_print_settings(pbio_port_t port, char *settings_string){
    pbio_error_t status = pbdrv_motor_status(port);
    if (status == PBIO_SUCCESS) {
        int8_t port_index = PORT_TO_IDX(port);
        char format_string [] = "Port: %c\nDirection: %s\nTorque limit: %f";
        if (dcmotor_settings[port_index].direction == PBIO_MOTOR_DIR_NORMAL) {
            snprintf(settings_string, MAX_DCMOTOR_SETTINGS_STR_LENGTH, format_string, port, "normal", dcmotor_settings[port_index].max_stall_duty / PBIO_DUTY_PCT_TO_ABS);
        }
        else{
            snprintf(settings_string, MAX_DCMOTOR_SETTINGS_STR_LENGTH, format_string, port, "inverted", dcmotor_settings[port_index].max_stall_duty / PBIO_DUTY_PCT_TO_ABS);
        }        
    }
    return status;
}

pbio_error_t pbio_dcmotor_coast(pbio_port_t port){
    return pbdrv_motor_coast_raw(port);
}

pbio_error_t pbio_dcmotor_brake(pbio_port_t port){
    return pbdrv_motor_set_duty_cycle_raw(port, 0);
}

pbio_error_t pbio_dcmotor_set_duty_cycle_int(pbio_port_t port, int16_t duty_cycle_int) {
    // Limit the duty cycle value
    int16_t limit = dcmotor_settings[PORT_TO_IDX(port)].max_stall_duty;
    if (duty_cycle_int > limit) {
        duty_cycle_int = limit;
    }
    if (duty_cycle_int < -limit) {
        duty_cycle_int = -limit;
    }
    // Flip sign if motor is inverted
    if (dcmotor_settings[PORT_TO_IDX(port)].direction == PBIO_MOTOR_DIR_INVERTED){
        duty_cycle_int = -duty_cycle_int;
    }
    return pbdrv_motor_set_duty_cycle_raw(port, duty_cycle_int);
}

pbio_error_t pbio_dcmotor_set_duty_cycle(pbio_port_t port, float_t duty_cycle) {
    int16_t duty_cycle_int = (int16_t) (PBIO_DUTY_PCT_TO_ABS * duty_cycle);
    return pbio_dcmotor_set_duty_cycle_int(port, duty_cycle_int);
}