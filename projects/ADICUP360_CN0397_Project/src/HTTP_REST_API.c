/**
******************************************************************************
*   @file     HTTP_REST_API.c
*   @brief    Source file for HTTP REST API Calls.
*   @version  V0.1
*   @author   ADI
*   @date     May 2016
*   @par Revision History:
*  - V0.1, May 2016: initial version.
*
*******************************************************************************
* Copyright 2016(c) Analog Devices, Inc.
*
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without modification,
* are permitted provided that the following conditions are met:
*  - Redistributions of source code must retain the above copyright
*    notice, this list of conditions and the following disclaimer.
*  - Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in
*    the documentation and/or other materials provided with the
*    distribution.
*  - Neither the name of Analog Devices, Inc. nor the names of its
*    contributors may be used to endorse or promote products derived
*    from this software without specific prior written permission.
*  - The use of this software may or may not infringe the patent rights
*    of one or more patent holders.  This license does not release you
*    from the requirement that you obtain separate licenses from these
*    patent holders to use this software.
*  - Use of the software either in source or binary form, must be run
*    on or directly connected to an Analog Devices Inc. component.
*
* THIS SOFTWARE IS PROVIDED BY ANALOG DEVICES "AS IS" AND ANY EXPRESS OR IMPLIED
* WARRANTIES, INCLUDING, BUT NOT LIMITED TO, NON-INFRINGEMENT, MERCHANTABILITY
* AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL ANALOG DEVICES BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
* SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
* INTELLECTUAL PROPERTY RIGHTS, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*******************************************************************************
**/

/***************************** Include Files **********************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "Timer.h"
#include "Communication.h"
#include "HTTP_REST_API.h"


/************************************************* Variable Definitions *****************************************************************/
char http_request[1000];



/************************************************* Function Definitions *****************************************************************/

/**
   @brief Constructs a HTTP REST API Call to create a Thing in the Analog Devices Connect instance

   @param none

   @return http_request - Create Thing HTTP REST API Call

**/

char* CreateThing_Request()
{
   memset(http_request,0,1000);
   char host[100], appkey[50], content_type[50], accept[50], content_length[50], payload[300];

   sprintf(http_request, "POST /Thingworx/Resources/EntityServices/Services/CreateThing HTTP/1.1\r\n");
   sprintf(host, "Host: %s\r\n",instance_url);
   sprintf(appkey, "appKey: %s\r\n",app_key);
   strcpy(content_type, "Content-Type: application/json\r\n");
   strcpy(accept, "Accept: application/json\r\n");
   sprintf(payload, " \n{\"name\":\"%s\", \"thingTemplateName\":\"%s\", \"description\": \"%s\" }\n\n",Thing_Name,ThingTemplate_Name,Thing_Description);
   sprintf(content_length, "Content-Length: %d\r\n",strlen(payload));

   strcat(http_request,host);
   strcat(http_request,appkey);
   strcat(http_request,content_type);
   strcat(http_request,accept);
   strcat(http_request,content_length);
   strcat(http_request,"\r\n");
   strcat(http_request,payload);

   return(http_request);
}


/**
   @brief Constructs a HTTP REST API Call to enable a Thing in the Analog Devices Connect instance

   @param none

   @return http_request - Enable Thing HTTP REST API Call

**/

char* EnableThing_Request()
{
   memset(http_request,0,1000);
   char host[100], appkey[50], content_type[50], accept[50], content_length[50], payload[300];

   sprintf(http_request, "POST /Thingworx/Things/%s/Services/EnableThing HTTP/1.1\r\n",Thing_Name);
   sprintf(host, "Host: %s\r\n",instance_url);
   sprintf(appkey, "appKey: %s\r\n",app_key);
   strcpy(content_type, "Content-Type: application/json\r\n");
   strcpy(accept, "Accept: application/json\r\n");
   sprintf(payload, " \n""\n\n");
   sprintf(content_length, "Content-Length: %d\r\n",strlen(payload));

   strcat(http_request,host);
   strcat(http_request,appkey);
   strcat(http_request,content_type);
   strcat(http_request,accept);
   strcat(http_request,content_length);
   strcat(http_request,"\r\n");
   strcat(http_request,payload);

   return(http_request);
}


/**
   @brief Constructs a HTTP REST API Call to restart a Thing in the Analog Devices Connect instance

   @param none

   @return http_request - Resart Thing HTTP REST API Call

**/

char* RestartThing_Request()
{
   memset(http_request,0,1000);
   char host[100], appkey[50], content_type[50], accept[50], content_length[50], payload[300];

   sprintf(http_request, "POST /Thingworx/Things/%s/Services/RestartThing HTTP/1.1\r\n",Thing_Name);
   sprintf(host, "Host: %s\r\n",instance_url);
   sprintf(appkey, "appKey: %s\r\n",app_key);
   strcpy(content_type, "Content-Type: application/json\r\n");
   strcpy(accept, "Accept: application/json\r\n");
   sprintf(payload, " \n""\n\n");
   sprintf(content_length, "Content-Length: %d\r\n",strlen(payload));

   strcat(http_request,host);
   strcat(http_request,appkey);
   strcat(http_request,content_type);
   strcat(http_request,accept);
   strcat(http_request,content_length);
   strcat(http_request,"\r\n");
   strcat(http_request,payload);

   return(http_request);
}


/**
   @brief Constructs a HTTP REST API Call to send sensor data to the Analog Devices Connect instance

   @param data1 -  Red Light Intensity
   @param data2 -  Green Light Intensity
   @param data3 -  Blue Light data

   @return http_request - Send Data HTTP REST API Call

**/

char* SendData_Request(float *data)
{
   memset(http_request,0,1000);
   char host[100], appkey[50], content_type[50], accept[50], content_length[50], payload[300];

   sprintf(http_request, "POST /Thingworx/Things/%s/Services/UpdateMyProperties?postParameter=PayloadJSON HTTP/1.1\r\n",Thing_Name);
   sprintf(host, "Host: %s\r\n",instance_url);
   sprintf(appkey, "appKey: %s\r\n",app_key);
   strcpy(content_type, "Content-Type: application/json\r\n");
   strcpy(accept, "Accept: application/json\r\n");
   sprintf(payload, " \n{\"%s\": %f, \"%s\": %f, \"%s\": %f}\n\n",Property1_Name, data[0], Property2_Name, data[1], Property3_Name, data[2]);
   sprintf(content_length, "Content-Length: %d\r\n",strlen(payload));


   strcat(http_request,host);
   strcat(http_request,appkey);
   strcat(http_request,content_type);
   strcat(http_request,accept);
   strcat(http_request,content_length);
   strcat(http_request,"\r\n");
   strcat(http_request,payload);

   return(http_request);
}


/**
   @brief Constructs a HTTP REST API Call sen information of the applicaton/firmware running on the ISM43340 WiFi module to the Analog Devices Connect instance

   @param data1 - Product ID
   @param data2 - Firmware Revision
   @param data3 - API Revision
   @param data4 - Stack Revision
   @param data5 - RTOS Revision
   @param data6 - CPU Clock

   @return http_request - Send Application Information HTTP REST API Call

**/

char* SendAppInfo_Request(char *data1, char *data2, char *data3, char *data4, char *data5, char* data6)
{
   memset(http_request,0,1000);
   char host[100], appkey[50], content_type[50], accept[50], content_length[50], payload[300];

   sprintf(http_request, "POST /Thingworx/Things/%s/Services/UpdateMyAppInfo?postParameter=Payload_AppInfo_JSON HTTP/1.1\r\n",Thing_Name);
   sprintf(host, "Host: %s\r\n",instance_url);
   sprintf(appkey, "appKey: %s\r\n",app_key);
   strcpy(content_type, "Content-Type: application/json\r\n");
   strcpy(accept, "Accept: application/json\r\n");
   sprintf(payload, " \n{\"prod_id\": \"%s\",\"fw_rev\": \"%s\",\"api_rev\": \"%s\",\"stack_rev\": \"%s\",\"rtos_rev\": \"%s\",\"cpu_clk\": \"%s\" }\n\n",data1,data2,data3,data4,data5,data6);
   sprintf(content_length, "Content-Length: %d\r\n",strlen(payload));


   strcat(http_request,host);
   strcat(http_request,appkey);
   strcat(http_request,content_type);
   strcat(http_request,accept);
   strcat(http_request,content_length);
   strcat(http_request,"\r\n");
   strcat(http_request,payload);

   return(http_request);
}



/**
   @brief Constructs a HTTP REST API Call to check if Thing already exists in the Analog Devices Connect instance

   @param none

   @return http_request - Get Property Values HTTP REST API Call

**/
char* GetPropertyValues_Request()
{
     memset(http_request,0,1000);
     char host[100], appkey[50], content_type[50], accept[50], content_length[50], payload[300];

     sprintf(http_request, "GET /Thingworx/Things/%s/Properties/%s HTTP/1.1\r\n",Thing_Name,Property1_Name);
     sprintf(host, "Host: %s\r\n",instance_url);
     sprintf(appkey, "appKey: %s\r\n",app_key);
     strcpy(content_type, "Content-Type: application/json\r\n");
     strcpy(accept, "Accept: application/json\r\n");
     sprintf(payload, " \n""\n\n");
     sprintf(content_length, "Content-Length: %d\r\n",strlen(payload));

     strcat(http_request,host);
     strcat(http_request,appkey);
     strcat(http_request,content_type);
     strcat(http_request,accept);
     strcat(http_request,content_length);
     strcat(http_request,"\r\n");
     strcat(http_request,payload);

     return(http_request);
}


/**
   @brief Constructs a HTTP REST API Call to update device location in the Analog Devices Connect instance

   @param latitude    - Latitude of device location
   @param longitude   - Longitude of device location
   @param elevation   - Elevation of device location

   @return http_request - Send Location HTTP REST API Call

**/
char* SendLocation_Request(float latitude, float longitude, float elevation)
{
   memset(http_request,0,1000);
   char host[100], appkey[50], content_type[50], accept[50], content_length[50],
   payload[300];

   sprintf(http_request, "PUT /Thingworx/Things/%s/Properties/Location HTTP/1.1\r\n",Thing_Name);
   sprintf(host, "Host: %s\r\n",instance_url);
   sprintf(appkey, "appKey: %s\r\n",app_key);
   strcpy(content_type, "Content-Type: application/json\r\n");
   strcpy(accept, "Accept: application/json\r\n");
   sprintf(payload, " \n{\"Location\": { \"latitude\": %f, \"longitude\": %f, \"elevation\": %f}}\n\n",
   latitude,longitude,elevation);
   sprintf(content_length, "Content-Length: %d\r\n",strlen(payload));

   strcat(http_request,host);
   strcat(http_request,appkey);
   strcat(http_request,content_type);
   strcat(http_request,accept);
   strcat(http_request,content_length);
   strcat(http_request,"\r\n");
   strcat(http_request,payload);

   return(http_request);
}

/****************************************************************************************************************************************/

