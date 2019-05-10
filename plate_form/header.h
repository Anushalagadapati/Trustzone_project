#ifndef HEADER_H
#define HEADER_H
#define PLAT_OPTEE  platform_structure_info()
	typedef struct os_information{
		char *os_name;
		char *os_version;
		char *os_provider;
		char *os_apiversion;
		}os_info_structure_t;

	static char* platform_optee(TEE_PropSetHandle h,const char *name);
	os_info_structure_t* platform_structure_info(void);
#endif
