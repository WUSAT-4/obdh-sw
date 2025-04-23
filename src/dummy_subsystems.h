#ifndef WUSAT_DUMMY_SUBSYSTEMS_H
#define WUSAT_DUMMY_SUBSYSTEMS_H

float get_battery_gauge();
void get_image_data(int*** image_buffer);
float get_payload_temp();
unsigned long get_timestamp();

#endif