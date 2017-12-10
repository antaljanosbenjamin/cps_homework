

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from UvegHaz.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#include <iosfwd>
#include <iomanip>

#include "rti/topic/cdr/Serialization.hpp"

#include "UvegHaz.hpp"
#include "UvegHazPlugin.hpp"

#include <rti/util/ostream_operators.hpp>

// ---- UvegHaz: 

UvegHaz::UvegHaz() :
    m_Value_ (0.0) ,
    m_TimeStamp_ (0)  {
}   

UvegHaz::UvegHaz (
    const std::string& ID,
    double Value,
    int32_t TimeStamp)
    :
        m_ID_( ID ),
        m_Value_( Value ),
        m_TimeStamp_( TimeStamp ) {
}

#ifdef RTI_CXX11_RVALUE_REFERENCES
#ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
UvegHaz::UvegHaz(UvegHaz&& other_) OMG_NOEXCEPT  :m_ID_ (std::move(other_.m_ID_))
,
m_Value_ (std::move(other_.m_Value_))
,
m_TimeStamp_ (std::move(other_.m_TimeStamp_))
{
} 

UvegHaz& UvegHaz::operator=(UvegHaz&&  other_) OMG_NOEXCEPT {
    UvegHaz tmp(std::move(other_));
    swap(tmp); 
    return *this;
}
#endif
#endif   

void UvegHaz::swap(UvegHaz& other_)  OMG_NOEXCEPT 
{
    using std::swap;
    swap(m_ID_, other_.m_ID_);
    swap(m_Value_, other_.m_Value_);
    swap(m_TimeStamp_, other_.m_TimeStamp_);
}  

bool UvegHaz::operator == (const UvegHaz& other_) const {
    if (m_ID_ != other_.m_ID_) {
        return false;
    }
    if (m_Value_ != other_.m_Value_) {
        return false;
    }
    if (m_TimeStamp_ != other_.m_TimeStamp_) {
        return false;
    }
    return true;
}
bool UvegHaz::operator != (const UvegHaz& other_) const {
    return !this->operator ==(other_);
}

// --- Getters and Setters: -------------------------------------------------
std::string& UvegHaz::ID() OMG_NOEXCEPT {
    return m_ID_;
}

const std::string& UvegHaz::ID() const OMG_NOEXCEPT {
    return m_ID_;
}

void UvegHaz::ID(const std::string& value) {
    m_ID_ = value;
}

double& UvegHaz::Value() OMG_NOEXCEPT {
    return m_Value_;
}

const double& UvegHaz::Value() const OMG_NOEXCEPT {
    return m_Value_;
}

void UvegHaz::Value(double value) {
    m_Value_ = value;
}

int32_t& UvegHaz::TimeStamp() OMG_NOEXCEPT {
    return m_TimeStamp_;
}

const int32_t& UvegHaz::TimeStamp() const OMG_NOEXCEPT {
    return m_TimeStamp_;
}

void UvegHaz::TimeStamp(int32_t value) {
    m_TimeStamp_ = value;
}

std::ostream& operator << (std::ostream& o,const UvegHaz& sample)
{
    rti::util::StreamFlagSaver flag_saver (o);
    o <<"[";
    o << "ID: " << sample.ID()<<", ";
    o << "Value: " << std::setprecision(15) <<sample.Value()<<", ";
    o << "TimeStamp: " << sample.TimeStamp() ;
    o <<"]";
    return o;
}

// --- Type traits: -------------------------------------------------

namespace rti { 
    namespace topic {

        template<>
        struct native_type_code<UvegHaz> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode UvegHaz_g_tc_ID_string = DDS_INITIALIZE_STRING_TYPECODE((255));
                static DDS_TypeCode_Member UvegHaz_g_tc_members[3]=
                {

                    {
                        (char *)"ID",/* Member name */
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
                        RTI_CDR_KEY_MEMBER , /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }, 
                    {
                        (char *)"Value",/* Member name */
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
                        (char *)"TimeStamp",/* Member name */
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

                static DDS_TypeCode UvegHaz_g_tc =
                {{
                        DDS_TK_STRUCT,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"UvegHaz", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        3, /* Number of members */
                        UvegHaz_g_tc_members, /* Members */
                        DDS_VM_NONE  /* Ignored */         
                    }}; /* Type code for UvegHaz*/

                if (is_initialized) {
                    return &UvegHaz_g_tc;
                }

                UvegHaz_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&UvegHaz_g_tc_ID_string;

                UvegHaz_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;

                UvegHaz_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;

                is_initialized = RTI_TRUE;

                return &UvegHaz_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::StructType& dynamic_type<UvegHaz>::get()
        {
            return static_cast<const dds::core::xtypes::StructType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<UvegHaz>::get())));
        }

    }
}  

namespace dds { 
    namespace topic {
        void topic_type_support<UvegHaz>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            rti::domain::register_type_plugin(
                participant,
                type_name,
                UvegHazPlugin_new,
                UvegHazPlugin_delete);
        }

        std::vector<char>& topic_type_support<UvegHaz>::to_cdr_buffer(
            std::vector<char>& buffer, const UvegHaz& sample)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = UvegHazPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = UvegHazPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support<UvegHaz>::from_cdr_buffer(UvegHaz& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = UvegHazPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create UvegHaz from cdr buffer");
        }

        void topic_type_support<UvegHaz>::reset_sample(UvegHaz& sample) 
        {
            rti::topic::reset_sample(sample.ID());
            rti::topic::reset_sample(sample.Value());
            rti::topic::reset_sample(sample.TimeStamp());
        }

        void topic_type_support<UvegHaz>::allocate_sample(UvegHaz& sample, int, int) 
        {
            rti::topic::allocate_sample(sample.ID(),  -1, 255);
        }

    }
}  

