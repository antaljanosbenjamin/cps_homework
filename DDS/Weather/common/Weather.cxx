

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from Weather.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#include <iosfwd>
#include <iomanip>

#include "rti/topic/cdr/Serialization.hpp"

#include "Weather.hpp"
#include "WeatherPlugin.hpp"

#include <rti/util/ostream_operators.hpp>

// ---- Weather: 

Weather::Weather() :
    m_temperature_ (0.0) ,
    m_tempTS_ (0u) ,
    m_pollution_ (0u) ,
    m_pollTS_ (0u)  {
}   

Weather::Weather (
    double temperature,
    uint32_t tempTS,
    uint32_t pollution,
    uint32_t pollTS)
    :
        m_temperature_( temperature ),
        m_tempTS_( tempTS ),
        m_pollution_( pollution ),
        m_pollTS_( pollTS ) {
}

#ifdef RTI_CXX11_RVALUE_REFERENCES
#ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
Weather::Weather(Weather&& other_) OMG_NOEXCEPT  :m_temperature_ (std::move(other_.m_temperature_))
,
m_tempTS_ (std::move(other_.m_tempTS_))
,
m_pollution_ (std::move(other_.m_pollution_))
,
m_pollTS_ (std::move(other_.m_pollTS_))
{
} 

Weather& Weather::operator=(Weather&&  other_) OMG_NOEXCEPT {
    Weather tmp(std::move(other_));
    swap(tmp); 
    return *this;
}
#endif
#endif   

void Weather::swap(Weather& other_)  OMG_NOEXCEPT 
{
    using std::swap;
    swap(m_temperature_, other_.m_temperature_);
    swap(m_tempTS_, other_.m_tempTS_);
    swap(m_pollution_, other_.m_pollution_);
    swap(m_pollTS_, other_.m_pollTS_);
}  

bool Weather::operator == (const Weather& other_) const {
    if (m_temperature_ != other_.m_temperature_) {
        return false;
    }
    if (m_tempTS_ != other_.m_tempTS_) {
        return false;
    }
    if (m_pollution_ != other_.m_pollution_) {
        return false;
    }
    if (m_pollTS_ != other_.m_pollTS_) {
        return false;
    }
    return true;
}
bool Weather::operator != (const Weather& other_) const {
    return !this->operator ==(other_);
}

// --- Getters and Setters: -------------------------------------------------
double& Weather::temperature() OMG_NOEXCEPT {
    return m_temperature_;
}

const double& Weather::temperature() const OMG_NOEXCEPT {
    return m_temperature_;
}

void Weather::temperature(double value) {
    m_temperature_ = value;
}

uint32_t& Weather::tempTS() OMG_NOEXCEPT {
    return m_tempTS_;
}

const uint32_t& Weather::tempTS() const OMG_NOEXCEPT {
    return m_tempTS_;
}

void Weather::tempTS(uint32_t value) {
    m_tempTS_ = value;
}

uint32_t& Weather::pollution() OMG_NOEXCEPT {
    return m_pollution_;
}

const uint32_t& Weather::pollution() const OMG_NOEXCEPT {
    return m_pollution_;
}

void Weather::pollution(uint32_t value) {
    m_pollution_ = value;
}

uint32_t& Weather::pollTS() OMG_NOEXCEPT {
    return m_pollTS_;
}

const uint32_t& Weather::pollTS() const OMG_NOEXCEPT {
    return m_pollTS_;
}

void Weather::pollTS(uint32_t value) {
    m_pollTS_ = value;
}

std::ostream& operator << (std::ostream& o,const Weather& sample)
{
    rti::util::StreamFlagSaver flag_saver (o);
    o <<"[";
    o << "temperature: " << std::setprecision(15) <<sample.temperature()<<", ";
    o << "tempTS: " << sample.tempTS()<<", ";
    o << "pollution: " << sample.pollution()<<", ";
    o << "pollTS: " << sample.pollTS() ;
    o <<"]";
    return o;
}

// --- Type traits: -------------------------------------------------

namespace rti { 
    namespace topic {

        template<>
        struct native_type_code<Weather> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member Weather_g_tc_members[4]=
                {

                    {
                        (char *)"temperature",/* Member name */
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
                        (char *)"tempTS",/* Member name */
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
                        (char *)"pollution",/* Member name */
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
                    }, 
                    {
                        (char *)"pollTS",/* Member name */
                        {
                            3,/* Representation ID */          
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

                static DDS_TypeCode Weather_g_tc =
                {{
                        DDS_TK_STRUCT,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"Weather", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        4, /* Number of members */
                        Weather_g_tc_members, /* Members */
                        DDS_VM_NONE  /* Ignored */         
                    }}; /* Type code for Weather*/

                if (is_initialized) {
                    return &Weather_g_tc;
                }

                Weather_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;

                Weather_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong;

                Weather_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong;

                Weather_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong;

                is_initialized = RTI_TRUE;

                return &Weather_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::StructType& dynamic_type<Weather>::get()
        {
            return static_cast<const dds::core::xtypes::StructType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<Weather>::get())));
        }

    }
}  

namespace dds { 
    namespace topic {
        void topic_type_support<Weather>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            rti::domain::register_type_plugin(
                participant,
                type_name,
                WeatherPlugin_new,
                WeatherPlugin_delete);
        }

        std::vector<char>& topic_type_support<Weather>::to_cdr_buffer(
            std::vector<char>& buffer, const Weather& sample)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = WeatherPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = WeatherPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support<Weather>::from_cdr_buffer(Weather& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = WeatherPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create Weather from cdr buffer");
        }

        void topic_type_support<Weather>::reset_sample(Weather& sample) 
        {
            rti::topic::reset_sample(sample.temperature());
            rti::topic::reset_sample(sample.tempTS());
            rti::topic::reset_sample(sample.pollution());
            rti::topic::reset_sample(sample.pollTS());
        }

        void topic_type_support<Weather>::allocate_sample(Weather& sample, int, int) 
        {
        }

    }
}  

