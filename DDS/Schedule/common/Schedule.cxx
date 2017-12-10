

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from Schedule.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#include <iosfwd>
#include <iomanip>

#include "rti/topic/cdr/Serialization.hpp"

#include "Schedule.hpp"
#include "SchedulePlugin.hpp"

#include <rti/util/ostream_operators.hpp>

// ---- Schedule: 

Schedule::Schedule() :
    m_scheduled_ (false) ,
    m_until_ (0u) ,
    m_sentTS_ (0u)  {
}   

Schedule::Schedule (
    bool scheduled,
    uint32_t until,
    uint32_t sentTS)
    :
        m_scheduled_( scheduled ),
        m_until_( until ),
        m_sentTS_( sentTS ) {
}

#ifdef RTI_CXX11_RVALUE_REFERENCES
#ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
Schedule::Schedule(Schedule&& other_) OMG_NOEXCEPT  :m_scheduled_ (std::move(other_.m_scheduled_))
,
m_until_ (std::move(other_.m_until_))
,
m_sentTS_ (std::move(other_.m_sentTS_))
{
} 

Schedule& Schedule::operator=(Schedule&&  other_) OMG_NOEXCEPT {
    Schedule tmp(std::move(other_));
    swap(tmp); 
    return *this;
}
#endif
#endif   

void Schedule::swap(Schedule& other_)  OMG_NOEXCEPT 
{
    using std::swap;
    swap(m_scheduled_, other_.m_scheduled_);
    swap(m_until_, other_.m_until_);
    swap(m_sentTS_, other_.m_sentTS_);
}  

bool Schedule::operator == (const Schedule& other_) const {
    if (m_scheduled_ != other_.m_scheduled_) {
        return false;
    }
    if (m_until_ != other_.m_until_) {
        return false;
    }
    if (m_sentTS_ != other_.m_sentTS_) {
        return false;
    }
    return true;
}
bool Schedule::operator != (const Schedule& other_) const {
    return !this->operator ==(other_);
}

// --- Getters and Setters: -------------------------------------------------
bool& Schedule::scheduled() OMG_NOEXCEPT {
    return m_scheduled_;
}

const bool& Schedule::scheduled() const OMG_NOEXCEPT {
    return m_scheduled_;
}

void Schedule::scheduled(bool value) {
    m_scheduled_ = value;
}

uint32_t& Schedule::until() OMG_NOEXCEPT {
    return m_until_;
}

const uint32_t& Schedule::until() const OMG_NOEXCEPT {
    return m_until_;
}

void Schedule::until(uint32_t value) {
    m_until_ = value;
}

uint32_t& Schedule::sentTS() OMG_NOEXCEPT {
    return m_sentTS_;
}

const uint32_t& Schedule::sentTS() const OMG_NOEXCEPT {
    return m_sentTS_;
}

void Schedule::sentTS(uint32_t value) {
    m_sentTS_ = value;
}

std::ostream& operator << (std::ostream& o,const Schedule& sample)
{
    rti::util::StreamFlagSaver flag_saver (o);
    o <<"[";
    o << "scheduled: " << sample.scheduled()<<", ";
    o << "until: " << sample.until()<<", ";
    o << "sentTS: " << sample.sentTS() ;
    o <<"]";
    return o;
}

// --- Type traits: -------------------------------------------------

namespace rti { 
    namespace topic {

        template<>
        struct native_type_code<Schedule> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member Schedule_g_tc_members[3]=
                {

                    {
                        (char *)"scheduled",/* Member name */
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
                        (char *)"until",/* Member name */
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
                        (char *)"sentTS",/* Member name */
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

                static DDS_TypeCode Schedule_g_tc =
                {{
                        DDS_TK_STRUCT,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"Schedule", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        3, /* Number of members */
                        Schedule_g_tc_members, /* Members */
                        DDS_VM_NONE  /* Ignored */         
                    }}; /* Type code for Schedule*/

                if (is_initialized) {
                    return &Schedule_g_tc;
                }

                Schedule_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_boolean;

                Schedule_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong;

                Schedule_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong;

                is_initialized = RTI_TRUE;

                return &Schedule_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::StructType& dynamic_type<Schedule>::get()
        {
            return static_cast<const dds::core::xtypes::StructType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<Schedule>::get())));
        }

    }
}  

namespace dds { 
    namespace topic {
        void topic_type_support<Schedule>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            rti::domain::register_type_plugin(
                participant,
                type_name,
                SchedulePlugin_new,
                SchedulePlugin_delete);
        }

        std::vector<char>& topic_type_support<Schedule>::to_cdr_buffer(
            std::vector<char>& buffer, const Schedule& sample)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = SchedulePlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = SchedulePlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support<Schedule>::from_cdr_buffer(Schedule& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = SchedulePlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create Schedule from cdr buffer");
        }

        void topic_type_support<Schedule>::reset_sample(Schedule& sample) 
        {
            rti::topic::reset_sample(sample.scheduled());
            rti::topic::reset_sample(sample.until());
            rti::topic::reset_sample(sample.sentTS());
        }

        void topic_type_support<Schedule>::allocate_sample(Schedule& sample, int, int) 
        {
        }

    }
}  

