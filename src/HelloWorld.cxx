

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from HelloWorld.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#include <iosfwd>
#include <iomanip>

#include "rti/topic/cdr/Serialization.hpp"

#include "HelloWorld.hpp"
#include "HelloWorldPlugin.hpp"

#include <rti/util/ostream_operators.hpp>

// ---- HelloWorld: 

HelloWorld::HelloWorld() :
    m_sampleId_ (0)  {
}   

HelloWorld::HelloWorld (
    const std::string& prefix,
    int32_t sampleId,
    const rti::core::bounded_sequence<uint8_t, (HELLODDS_MAX_PAYLOAD_SIZE)>& payload)
    :
        m_prefix_( prefix ),
        m_sampleId_( sampleId ),
        m_payload_( payload ) {
}

#ifdef RTI_CXX11_RVALUE_REFERENCES
#ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
HelloWorld::HelloWorld(HelloWorld&& other_) OMG_NOEXCEPT  :m_prefix_ (std::move(other_.m_prefix_))
,
m_sampleId_ (std::move(other_.m_sampleId_))
,
m_payload_ (std::move(other_.m_payload_))
{
} 

HelloWorld& HelloWorld::operator=(HelloWorld&&  other_) OMG_NOEXCEPT {
    HelloWorld tmp(std::move(other_));
    swap(tmp); 
    return *this;
}
#endif
#endif   

void HelloWorld::swap(HelloWorld& other_)  OMG_NOEXCEPT 
{
    using std::swap;
    swap(m_prefix_, other_.m_prefix_);
    swap(m_sampleId_, other_.m_sampleId_);
    swap(m_payload_, other_.m_payload_);
}  

bool HelloWorld::operator == (const HelloWorld& other_) const {
    if (m_prefix_ != other_.m_prefix_) {
        return false;
    }
    if (m_sampleId_ != other_.m_sampleId_) {
        return false;
    }
    if (m_payload_ != other_.m_payload_) {
        return false;
    }
    return true;
}
bool HelloWorld::operator != (const HelloWorld& other_) const {
    return !this->operator ==(other_);
}

// --- Getters and Setters: -------------------------------------------------
std::string& HelloWorld::prefix() OMG_NOEXCEPT {
    return m_prefix_;
}

const std::string& HelloWorld::prefix() const OMG_NOEXCEPT {
    return m_prefix_;
}

void HelloWorld::prefix(const std::string& value) {
    m_prefix_ = value;
}

int32_t& HelloWorld::sampleId() OMG_NOEXCEPT {
    return m_sampleId_;
}

const int32_t& HelloWorld::sampleId() const OMG_NOEXCEPT {
    return m_sampleId_;
}

void HelloWorld::sampleId(int32_t value) {
    m_sampleId_ = value;
}

rti::core::bounded_sequence<uint8_t, (HELLODDS_MAX_PAYLOAD_SIZE)>& HelloWorld::payload() OMG_NOEXCEPT {
    return m_payload_;
}

const rti::core::bounded_sequence<uint8_t, (HELLODDS_MAX_PAYLOAD_SIZE)>& HelloWorld::payload() const OMG_NOEXCEPT {
    return m_payload_;
}

void HelloWorld::payload(const rti::core::bounded_sequence<uint8_t, (HELLODDS_MAX_PAYLOAD_SIZE)>& value) {
    m_payload_ = value;
}

std::ostream& operator << (std::ostream& o,const HelloWorld& sample)
{
    rti::util::StreamFlagSaver flag_saver (o);
    o <<"[";
    o << "prefix: " << sample.prefix()<<", ";
    o << "sampleId: " << sample.sampleId()<<", ";
    o << "payload: " << sample.payload() ;
    o <<"]";
    return o;
}

// --- Type traits: -------------------------------------------------

namespace rti { 
    namespace topic {

        template<>
        struct native_type_code<HelloWorld> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode HelloWorld_g_tc_prefix_string = DDS_INITIALIZE_STRING_TYPECODE(((HELLODDS_MAX_STRING_SIZE)));
                static DDS_TypeCode HelloWorld_g_tc_payload_sequence = DDS_INITIALIZE_SEQUENCE_TYPECODE(((HELLODDS_MAX_PAYLOAD_SIZE)),NULL);
                static DDS_TypeCode_Member HelloWorld_g_tc_members[3]=
                {

                    {
                        (char *)"prefix",/* Member name */
                        {
                            0,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }, 
                    {
                        (char *)"sampleId",/* Member name */
                        {
                            1,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }, 
                    {
                        (char *)"payload",/* Member name */
                        {
                            2,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }
                };

                static DDS_TypeCode HelloWorld_g_tc =
                {{
                        DDS_TK_STRUCT,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"HelloWorld", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        3, /* Number of members */
                        HelloWorld_g_tc_members, /* Members */
                        DDS_VM_NONE  /* Ignored */         
                    }}; /* Type code for HelloWorld*/

                if (is_initialized) {
                    return &HelloWorld_g_tc;
                }

                HelloWorld_g_tc_payload_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;

                HelloWorld_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&HelloWorld_g_tc_prefix_string;

                HelloWorld_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;

                HelloWorld_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)& HelloWorld_g_tc_payload_sequence;

                is_initialized = RTI_TRUE;

                return &HelloWorld_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::StructType& dynamic_type<HelloWorld>::get()
        {
            return static_cast<const dds::core::xtypes::StructType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<HelloWorld>::get())));
        }

    }
}  

namespace dds { 
    namespace topic {
        void topic_type_support<HelloWorld>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            rti::domain::register_type_plugin(
                participant,
                type_name,
                HelloWorldPlugin_new,
                HelloWorldPlugin_delete);
        }

        std::vector<char>& topic_type_support<HelloWorld>::to_cdr_buffer(
            std::vector<char>& buffer, const HelloWorld& sample)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = HelloWorldPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = HelloWorldPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support<HelloWorld>::from_cdr_buffer(HelloWorld& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = HelloWorldPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create HelloWorld from cdr buffer");
        }

        void topic_type_support<HelloWorld>::reset_sample(HelloWorld& sample) 
        {
            rti::topic::reset_sample(sample.prefix());
            rti::topic::reset_sample(sample.sampleId());
            rti::topic::reset_sample(sample.payload());
        }

        void topic_type_support<HelloWorld>::allocate_sample(HelloWorld& sample, int, int) 
        {
            rti::topic::allocate_sample(sample.prefix(),  -1, (HELLODDS_MAX_STRING_SIZE));
            rti::topic::allocate_sample(sample.payload(),  (HELLODDS_MAX_PAYLOAD_SIZE), -1);
        }

    }
}  

