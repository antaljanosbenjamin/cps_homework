

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from UvegHaz.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef UvegHazPlugin_512309000_h
#define UvegHazPlugin_512309000_h

#include "UvegHaz.hpp"

struct RTICdrStream;

#ifndef pres_typePlugin_h
#include "pres/pres_typePlugin.h"
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

/* The type used to store keys for instances of type struct
* AnotherSimple.
*
* By default, this type is struct UvegHaz
* itself. However, if for some reason this choice is not practical for your
* system (e.g. if sizeof(struct UvegHaz)
* is very large), you may redefine this typedef in terms of another type of
* your choosing. HOWEVER, if you define the KeyHolder type to be something
* other than struct AnotherSimple, the
* following restriction applies: the key of struct
* UvegHaz must consist of a
* single field of your redefined KeyHolder type and that field must be the
* first field in struct UvegHaz.
*/
typedef  class UvegHaz UvegHazKeyHolder;

#define UvegHazPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define UvegHazPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define UvegHazPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

#define UvegHazPlugin_get_key PRESTypePluginDefaultEndpointData_getKey 
#define UvegHazPlugin_return_key PRESTypePluginDefaultEndpointData_returnKey

#define UvegHazPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define UvegHazPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern UvegHaz*
UvegHazPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern UvegHaz*
UvegHazPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern UvegHaz*
UvegHazPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
UvegHazPluginSupport_copy_data(
    UvegHaz *out,
    const UvegHaz *in);

NDDSUSERDllExport extern void 
UvegHazPluginSupport_destroy_data_w_params(
    UvegHaz *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
UvegHazPluginSupport_destroy_data_ex(
    UvegHaz *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
UvegHazPluginSupport_destroy_data(
    UvegHaz *sample);

NDDSUSERDllExport extern void 
UvegHazPluginSupport_print_data(
    const UvegHaz *sample,
    const char *desc,
    unsigned int indent);

NDDSUSERDllExport extern UvegHaz*
UvegHazPluginSupport_create_key_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern UvegHaz*
UvegHazPluginSupport_create_key(void);

NDDSUSERDllExport extern void 
UvegHazPluginSupport_destroy_key_ex(
    UvegHazKeyHolder *key,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
UvegHazPluginSupport_destroy_key(
    UvegHazKeyHolder *key);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
UvegHazPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
UvegHazPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);

NDDSUSERDllExport extern PRESTypePluginEndpointData 
UvegHazPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
UvegHazPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern void    
UvegHazPlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    UvegHaz *sample,
    void *handle);    

NDDSUSERDllExport extern RTIBool 
UvegHazPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    UvegHaz *out,
    const UvegHaz *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
UvegHazPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const UvegHaz *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
UvegHazPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    UvegHaz *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
UvegHazPlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const UvegHaz *sample); 

NDDSUSERDllExport extern RTIBool 
UvegHazPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    UvegHaz **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
UvegHazPlugin_deserialize_from_cdr_buffer(
    UvegHaz *sample,
    const char * buffer,
    unsigned int length);    

NDDSUSERDllExport extern RTIBool
UvegHazPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
UvegHazPlugin_get_serialized_sample_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);    

NDDSUSERDllExport extern unsigned int 
UvegHazPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
UvegHazPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
UvegHazPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const UvegHaz * sample);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
UvegHazPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
UvegHazPlugin_get_serialized_key_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
UvegHazPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
UvegHazPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const UvegHaz *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
UvegHazPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    UvegHaz * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
UvegHazPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    UvegHaz ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
UvegHazPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    UvegHaz *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
UvegHazPlugin_instance_to_key(
    PRESTypePluginEndpointData endpoint_data,
    UvegHazKeyHolder *key, 
    const UvegHaz *instance);

NDDSUSERDllExport extern RTIBool 
UvegHazPlugin_key_to_instance(
    PRESTypePluginEndpointData endpoint_data,
    UvegHaz *instance, 
    const UvegHazKeyHolder *key);

NDDSUSERDllExport extern RTIBool 
UvegHazPlugin_instance_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    DDS_KeyHash_t *keyhash,
    const UvegHaz *instance);

NDDSUSERDllExport extern RTIBool 
UvegHazPlugin_serialized_sample_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    DDS_KeyHash_t *keyhash,
    RTIBool deserialize_encapsulation,
    void *endpoint_plugin_qos); 

/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
UvegHazPlugin_new(void);

NDDSUSERDllExport extern void
UvegHazPlugin_delete(struct PRESTypePlugin *);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* UvegHazPlugin_512309000_h */

