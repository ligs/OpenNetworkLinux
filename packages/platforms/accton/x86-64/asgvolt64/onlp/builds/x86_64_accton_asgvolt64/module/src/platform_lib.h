/************************************************************
 * <bsn.cl fy=2014 v=onl>
 *
 *           Copyright 2014 Big Switch Networks, Inc.
 *           Copyright 2014 Accton Technology Corporation.
 *
 * Licensed under the Eclipse Public License, Version 1.0 (the
 * "License"); you may not use this file except in compliance
 * with the License. You may obtain a copy of the License at
 *
 *        http://www.eclipse.org/legal/epl-v10.html
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific
 * language governing permissions and limitations under the
 * License.
 *
 * </bsn.cl>
 ************************************************************
 *
 *
 *
 ***********************************************************/
#ifndef __PLATFORM_LIB_H__
#define __PLATFORM_LIB_H__

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <linux/sockios.h>
#include <errno.h> 
#include "x86_64_accton_asgvolt64_log.h"

#define CHASSIS_FAN_COUNT		4
#define CHASSIS_THERMAL_COUNT	        8
#define CHASSIS_PSU_COUNT		2
#define CHASSIS_LED_COUNT		6

#define PSU1_ID 1
#define PSU2_ID 2

#define PSU_SYSFS_PATH  "/sys/devices/platform/asgvolt64_psu/"
#define FAN_BOARD_PATH	"/sys/devices/platform/asgvolt64_fan/"
#define IDPROM_PATH     "/sys/bus/i2c/devices/0-0057/eeprom"

int onlp_file_write_integer(char *filename, int value);
int onlp_file_read_binary(char *filename, char *buffer, int buf_size, int data_len);
int onlp_file_read_string(char *filename, char *buffer, int buf_size, int data_len);
int mdio_read(int skfd, int location, struct ifreq ifr);
void mdio_write(int skfd, int location, int value, struct ifreq ifr);


struct mii_data {
    unsigned short  int	phy_id;
    unsigned short  int	reg_num;
    unsigned short  int	val_in;
    unsigned short  int	val_out;
};


enum onlp_thermal_id
{
    THERMAL_RESERVED = 0,
    THERMAL_CPU_CORE,
    THERMAL_1_ON_MAIN_BROAD,
    THERMAL_2_ON_MAIN_BROAD,
    THERMAL_3_ON_MAIN_BROAD,
    THERMAL_4_ON_MAIN_BROAD,
    THERMAL_5_ON_MAIN_BROAD,
    THERMAL_6_ON_MAIN_BROAD,
    THERMAL_7_ON_MAIN_BROAD,
    THERMAL_1_ON_PSU1,
    THERMAL_1_ON_PSU2,
};

#define DEBUG_MODE 0

#if (DEBUG_MODE == 1)
	#define DEBUG_PRINT(fmt, args...)                                        \
		printf("%s:%s[%d]: " fmt "\r\n", __FILE__, __FUNCTION__, __LINE__, ##args)
#else
	#define DEBUG_PRINT(fmt, args...)
#endif

#endif  /* __PLATFORM_LIB_H__ */


