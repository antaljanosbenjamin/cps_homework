

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from Decision.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#include <iosfwd>
#include <iomanip>

#include "rti/topic/cdr/Serialization.hpp"

#include "Decision.hpp"
#include "DecisionPlugin.hpp"

#include <rti/util/ostream_operators.hpp>

std::ostream& operator << (std::ostream& o,const Decision& sample)
{
    rti::util::StreamFlagSaver flag_saver (o);
    switch(sample.underlying()){
        case Decision::OPEN:
        o << "Decision::OPEN" << " ";
        break;
        case Decision::CLOSE:
        o << "Decision::CLOSE" << " ";
        break;
    }
    return o;
}

// ---- DecisionInfo: 

DecisionInfo::DecisionInfo() :
    m_decisionTS_ (0u) ,
    m_decision_(Decision::get_default())  {
}   

DecisionInfo::DecisionInfo (
    uint32_t decisionTS,
    const Decision& decision,
    const Config& config,
    const Weather& lastWeather,
    const Schedule& lastSchedule)
    :
        m_decisionTS_( decisionTS ),
        m_decision_( decision ),
        m_config_( config ),
        m_lastWeather_( lastWeather ),
        m_lastSchedule_( lastSchedule ) {
}

#ifdef RTI_CXX11_RVALUE_REFERENCES
#ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
DecisionInfo::DecisionInfo(DecisionInfo&& other_) OMG_NOEXCEPT  :m_decisionTS_ (std::move(other_.m_decisionTS_))
,
m_decision_ (std::move(other_.m_decision_))
,
m_config_ (std::move(other_.m_config_))
,
m_lastWeather_ (std::move(other_.m_lastWeather_))
,
m_lastSchedule_ (std::move(other_.m_lastSchedule_))
{
} 

DecisionInfo& DecisionInfo::operator=(DecisionInfo&&  other_) OMG_NOEXCEPT {
    DecisionInfo tmp(std::move(other_));
    swap(tmp); 
    return *this;
}
#endif
#endif   

void DecisionInfo::swap(DecisionInfo& other_)  OMG_NOEXCEPT 
{
    using std::swap;
    swap(m_decisionTS_, other_.m_decisionTS_);
    swap(m_decision_, other_.m_decision_);
    swap(m_config_, other_.m_config_);
    swap(m_lastWeather_, other_.m_lastWeather_);
    swap(m_lastSchedule_, other_.m_lastSchedule_);
}  

bool DecisionInfo::operator == (const DecisionInfo& other_) const {
    if (m_decisionTS_ != other_.m_decisionTS_) {
        return false;
    }
    if (m_decision_ != other_.m_decision_) {
        return false;
    }
    if (m_config_ != other_.m_config_) {
        return false;
    }
    if (m_lastWeather_ != other_.m_lastWeather_) {
        return false;
    }
    if (m_lastSchedule_ != other_.m_lastSchedule_) {
        return false;
    }
    return true;
}
bool DecisionInfo::operator != (const DecisionInfo& other_) const {
    return !this->operator ==(other_);
}

// --- Getters and Setters: -------------------------------------------------
uint32_t& DecisionInfo::decisionTS() OMG_NOEXCEPT {
    return m_decisionTS_;
}

const uint32_t& DecisionInfo::decisionTS() const OMG_NOEXCEPT {
    return m_decisionTS_;
}

void DecisionInfo::decisionTS(uint32_t value) {
    m_decisionTS_ = value;
}

Decision& DecisionInfo::decision() OMG_NOEXCEPT {
    return m_decision_;
}

const Decision& DecisionInfo::decision() const OMG_NOEXCEPT {
    return m_decision_;
}

void DecisionInfo::decision(const Decision& value) {
    m_decision_ = value;
}

Config& DecisionInfo::config() OMG_NOEXCEPT {
    return m_config_;
}

const Config& DecisionInfo::config() const OMG_NOEXCEPT {
    return m_config_;
}

void DecisionInfo::config(const Config& value) {
    m_config_ = value;
}

Weather& DecisionInfo::lastWeather() OMG_NOEXCEPT {
    return m_lastWeather_;
}

const Weather& DecisionInfo::lastWeather() const OMG_NOEXCEPT {
    return m_lastWeather_;
}

void DecisionInfo::lastWeather(const Weather& value) {
    m_lastWeather_ = value;
}

Schedule& DecisionInfo::lastSchedule() OMG_NOEXCEPT {
    return m_lastSchedule_;
}

const Schedule& DecisionInfo::lastSchedule() const OMG_NOEXCEPT {
    return m_lastSchedule_;
}

void DecisionInfo::lastSchedule(const Schedule& value) {
    m_lastSchedule_ = value;
}

std::ostream& operator << (std::ostream& o,const DecisionInfo& sample)
{
    rti::util::StreamFlagSaver flag_saver (o);
    o <<"[";
    o << "decisionTS: " << sample.decisionTS()<<", ";
    o << "decision: " << sample.decision()<<", ";
    o << "config: " << sample.config()<<", ";
    o << "lastWeather: " << sample.lastWeather()<<", ";
    o << "lastSchedule: " << sample.lastSchedule() ;
    o <<"]";
    return o;
}

// --- Type traits: -------------------------------------------------

namespace rti { 
    namespace topic {

        template<>
        struct native_type_code<Decision> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member Decision_g_tc_members[2]=
                {

                    {
                        (char *)"OPEN",/* Member name */
                        {
                            0, /* Ignored */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        Decision::OPEN, 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL/* Ignored */
                    }, 
                    {
                        (char *)"CLOSE",/* Member name */
                        {
                            0, /* Ignored */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        Decision::CLOSE, 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL/* Ignored */
                    }
                };

                static DDS_TypeCode Decision_g_tc =
                {{
                        DDS_TK_ENUM,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"Decision", /* Name */
                        NULL,     /* Base class type code is assigned later */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        2, /* Number of members */
                        Decision_g_tc_members, /* Members */
                        DDS_VM_NONE   /* Type Modifier */        
                    }}; /* Type code for Decision*/

                if (is_initialized) {
                    return &Decision_g_tc;
                }

                is_initialized = RTI_TRUE;

                return &Decision_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::EnumType& dynamic_type<Decision>::get()
        {
            return static_cast<const dds::core::xtypes::EnumType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<Decision>::get())));
        }

        template<>
        struct native_type_code<DecisionInfo> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member DecisionInfo_g_tc_members[5]=
                {

                    {
                        (char *)"decisionTS",/* Member name */
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
                        (char *)"decision",/* Member name */
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
                        (char *)"config",/* Member name */
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
                        (char *)"lastWeather",/* Member name */
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
                    }, 
                    {
                        (char *)"lastSchedule",/* Member name */
                        {
                            4,/* Representation ID */          
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

                static DDS_TypeCode DecisionInfo_g_tc =
                {{
                        DDS_TK_STRUCT,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"DecisionInfo", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        5, /* Number of members */
                        DecisionInfo_g_tc_members, /* Members */
                        DDS_VM_NONE  /* Ignored */         
                    }}; /* Type code for DecisionInfo*/

                if (is_initialized) {
                    return &DecisionInfo_g_tc;
                }

                DecisionInfo_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong;

                DecisionInfo_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&rti::topic::dynamic_type< Decision>::get().native();

                DecisionInfo_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&rti::topic::dynamic_type< Config>::get().native();

                DecisionInfo_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&rti::topic::dynamic_type< Weather>::get().native();

                DecisionInfo_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&rti::topic::dynamic_type< Schedule>::get().native();

                is_initialized = RTI_TRUE;

                return &DecisionInfo_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::StructType& dynamic_type<DecisionInfo>::get()
        {
            return static_cast<const dds::core::xtypes::StructType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<DecisionInfo>::get())));
        }

    }
}  

namespace dds { 
    namespace topic {
        void topic_type_support<DecisionInfo>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            rti::domain::register_type_plugin(
                participant,
                type_name,
                DecisionInfoPlugin_new,
                DecisionInfoPlugin_delete);
        }

        std::vector<char>& topic_type_support<DecisionInfo>::to_cdr_buffer(
            std::vector<char>& buffer, const DecisionInfo& sample)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = DecisionInfoPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = DecisionInfoPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support<DecisionInfo>::from_cdr_buffer(DecisionInfo& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = DecisionInfoPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create DecisionInfo from cdr buffer");
        }

        void topic_type_support<DecisionInfo>::reset_sample(DecisionInfo& sample) 
        {
            rti::topic::reset_sample(sample.decisionTS());
            rti::topic::reset_sample(sample.decision());
            rti::topic::reset_sample(sample.config());
            rti::topic::reset_sample(sample.lastWeather());
            rti::topic::reset_sample(sample.lastSchedule());
        }

        void topic_type_support<DecisionInfo>::allocate_sample(DecisionInfo& sample, int, int) 
        {
            rti::topic::allocate_sample(sample.decision(),  -1, -1);
            rti::topic::allocate_sample(sample.config(),  -1, -1);
            rti::topic::allocate_sample(sample.lastWeather(),  -1, -1);
            rti::topic::allocate_sample(sample.lastSchedule(),  -1, -1);
        }

    }
}  

