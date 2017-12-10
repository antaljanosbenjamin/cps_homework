

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from Config.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#include <iosfwd>
#include <iomanip>

#include "rti/topic/cdr/Serialization.hpp"

#include "Config.hpp"
#include "ConfigPlugin.hpp"

#include <rti/util/ostream_operators.hpp>

// ---- Config: 

Config::Config() :
    m_maxTemperature_ (0.0) ,
    m_maxPollution_ (0u) ,
    m_minHumidity_ (0u) ,
    m_maxHumidity_ (0u)  {
}   

Config::Config (
    double maxTemperature,
    uint32_t maxPollution,
    uint32_t minHumidity,
    uint32_t maxHumidity)
    :
        m_maxTemperature_( maxTemperature ),
        m_maxPollution_( maxPollution ),
        m_minHumidity_( minHumidity ),
        m_maxHumidity_( maxHumidity ) {
}

#ifdef RTI_CXX11_RVALUE_REFERENCES
#ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
Config::Config(Config&& other_) OMG_NOEXCEPT  :m_maxTemperature_ (std::move(other_.m_maxTemperature_))
,
m_maxPollution_ (std::move(other_.m_maxPollution_))
,
m_minHumidity_ (std::move(other_.m_minHumidity_))
,
m_maxHumidity_ (std::move(other_.m_maxHumidity_))
{
} 

Config& Config::operator=(Config&&  other_) OMG_NOEXCEPT {
    Config tmp(std::move(other_));
    swap(tmp); 
    return *this;
}
#endif
#endif   

void Config::swap(Config& other_)  OMG_NOEXCEPT 
{
    using std::swap;
    swap(m_maxTemperature_, other_.m_maxTemperature_);
    swap(m_maxPollution_, other_.m_maxPollution_);
    swap(m_minHumidity_, other_.m_minHumidity_);
    swap(m_maxHumidity_, other_.m_maxHumidity_);
}  

bool Config::operator == (const Config& other_) const {
    if (m_maxTemperature_ != other_.m_maxTemperature_) {
        return false;
    }
    if (m_maxPollution_ != other_.m_maxPollution_) {
        return false;
    }
    if (m_minHumidity_ != other_.m_minHumidity_) {
        return false;
    }
    if (m_maxHumidity_ != other_.m_maxHumidity_) {
        return false;
    }
    return true;
}
bool Config::operator != (const Config& other_) const {
    return !this->operator ==(other_);
}

// --- Getters and Setters: -------------------------------------------------
double& Config::maxTemperature() OMG_NOEXCEPT {
    return m_maxTemperature_;
}

const double& Config::maxTemperature() const OMG_NOEXCEPT {
    return m_maxTemperature_;
}

void Config::maxTemperature(double value) {
    m_maxTemperature_ = value;
}

uint32_t& Config::maxPollution() OMG_NOEXCEPT {
    return m_maxPollution_;
}

const uint32_t& Config::maxPollution() const OMG_NOEXCEPT {
    return m_maxPollution_;
}

void Config::maxPollution(uint32_t value) {
    m_maxPollution_ = value;
}

uint32_t& Config::minHumidity() OMG_NOEXCEPT {
    return m_minHumidity_;
}

const uint32_t& Config::minHumidity() const OMG_NOEXCEPT {
    return m_minHumidity_;
}

void Config::minHumidity(uint32_t value) {
    m_minHumidity_ = value;
}

uint32_t& Config::maxHumidity() OMG_NOEXCEPT {
    return m_maxHumidity_;
}

const uint32_t& Config::maxHumidity() const OMG_NOEXCEPT {
    return m_maxHumidity_;
}

void Config::maxHumidity(uint32_t value) {
    m_maxHumidity_ = value;
}

std::ostream& operator << (std::ostream& o,const Config& sample)
{
    rti::util::StreamFlagSaver flag_saver (o);
    o <<"[";
    o << "maxTemperature: " << std::setprecision(15) <<sample.maxTemperature()<<", ";
    o << "maxPollution: " << sample.maxPollution()<<", ";
    o << "minHumidity: " << sample.minHumidity()<<", ";
    o << "maxHumidity: " << sample.maxHumidity() ;
    o <<"]";
    return o;
}

// --- Type traits: -------------------------------------------------

namespace rti { 
    namespace topic {

        template<>
        struct native_type_code<Config> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member Config_g_tc_members[4]=
                {

                    {
                        (char *)"maxTemperature",/* Member name */
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
                        (char *)"maxPollution",/* Member name */
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
                        (char *)"minHumidity",/* Member name */
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
                        (char *)"maxHumidity",/* Member name */
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

                static DDS_TypeCode Config_g_tc =
                {{
                        DDS_TK_STRUCT,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"Config", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        4, /* Number of members */
                        Config_g_tc_members, /* Members */
                        DDS_VM_NONE  /* Ignored */         
                    }}; /* Type code for Config*/

                if (is_initialized) {
                    return &Config_g_tc;
                }

                Config_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;

                Config_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong;

                Config_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong;

                Config_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong;

                is_initialized = RTI_TRUE;

                return &Config_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::StructType& dynamic_type<Config>::get()
        {
            return static_cast<const dds::core::xtypes::StructType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<Config>::get())));
        }

    }
}  

namespace dds { 
    namespace topic {
        void topic_type_support<Config>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            rti::domain::register_type_plugin(
                participant,
                type_name,
                ConfigPlugin_new,
                ConfigPlugin_delete);
        }

        std::vector<char>& topic_type_support<Config>::to_cdr_buffer(
            std::vector<char>& buffer, const Config& sample)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = ConfigPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = ConfigPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support<Config>::from_cdr_buffer(Config& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = ConfigPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create Config from cdr buffer");
        }

        void topic_type_support<Config>::reset_sample(Config& sample) 
        {
            rti::topic::reset_sample(sample.maxTemperature());
            rti::topic::reset_sample(sample.maxPollution());
            rti::topic::reset_sample(sample.minHumidity());
            rti::topic::reset_sample(sample.maxHumidity());
        }

        void topic_type_support<Config>::allocate_sample(Config& sample, int, int) 
        {
        }

    }
}  

