/* platform information storing in strucure */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <utee_syscalls.h>
#include<header.h>

os_info_structure_t* platform_structure_info()
{
 os_info_structure_t *os_info;
 os_info=(os_info_structure_t *)malloc(sizeof(os_info_structure_t));
	if(os_info==0)
	{
	IMSG("error\n");
	}
	#ifdef PLAT_OPTEE
	   os_info->os_name= platform_optee(TEE_PROPSET_TEE_IMPLEMENTATION,
					"gpd.tee.description");
	   os_info->os_apiversion= platform_optee(TEE_PROPSET_TEE_IMPLEMENTATION,
					"gpd.tee.apiversion");
	   os_info->os_version= platform_optee(TEE_PROPSET_TEE_IMPLEMENTATION,
					"gpd.tee.trustedos.implementation.version");
	   os_info->os_provider= platform_optee(TEE_PROPSET_TEE_IMPLEMENTATION,
					"gpd.tee.trustedos.manufacturer");
	   	return os_info;
	#endif
}

static char* platform_optee(TEE_PropSetHandle h,const char *name)
{
	char *buf;
	TEE_Result res;
	uint32_t prop_type;
	uint32_t index;
	int s=1024;
	buf=(char *)malloc(1024*sizeof(char));
	if(buf==NULL)
		return -1;
	  enum user_ta_prop_type *type;
	res = utee_get_property_name_to_index((unsigned long)h, name,
						strlen(name) + 1, &index);
		if (res != TEE_SUCCESS)
			return res;
	res = utee_get_property((unsigned long)h, index, NULL, NULL,
					buf, &s, &prop_type);
		if (res != TEE_SUCCESS)
			return res;
		else
			return buf;
}


