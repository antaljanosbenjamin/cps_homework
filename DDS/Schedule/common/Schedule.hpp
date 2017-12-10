

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from Schedule.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef Schedule_1325351769_hpp
#define Schedule_1325351769_hpp

#include <iosfwd>

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef RTIUSERDllExport
#define RTIUSERDllExport __declspec(dllexport)
#endif

#include "dds/domain/DomainParticipant.hpp"
#include "dds/topic/TopicTraits.hpp"
#include "dds/core/SafeEnumeration.hpp"
#include "dds/core/String.hpp"
#include "dds/core/array.hpp"
#include "dds/core/vector.hpp"
#include "dds/core/Optional.hpp"
#include "dds/core/xtypes/DynamicType.hpp"
#include "dds/core/xtypes/StructType.hpp"
#include "dds/core/xtypes/UnionType.hpp"
#include "dds/core/xtypes/EnumType.hpp"
#include "dds/core/xtypes/AliasType.hpp"
#include "rti/core/array.hpp"
#include "rti/core/BoundedSequence.hpp"
#include "rti/util/StreamFlagSaver.hpp"
#include "rti/domain/PluginSupport.hpp"
#include "rti/core/LongDouble.hpp"
#include "dds/core/External.hpp"
#include "rti/core/Pointer.hpp"
#include "rti/topic/TopicTraits.hpp"
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef RTIUSERDllExport
#define RTIUSERDllExport
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

class NDDSUSERDllExport Schedule {

  public:
    Schedule();
    Schedule(
        bool scheduled,
        uint32_t until,
        uint32_t sentTS);

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    Schedule (Schedule&&) = default;
    Schedule& operator=(Schedule&&) = default;
    Schedule& operator=(const Schedule&) = default;
    Schedule(const Schedule&) = default;
    #else
    Schedule(Schedule&& other_) OMG_NOEXCEPT;  
    Schedule& operator=(Schedule&&  other_) OMG_NOEXCEPT;
    #endif
    #endif 

    bool& scheduled() OMG_NOEXCEPT; 
    const bool& scheduled() const OMG_NOEXCEPT;
    void scheduled(bool value);

    uint32_t& until() OMG_NOEXCEPT; 
    const uint32_t& until() const OMG_NOEXCEPT;
    void until(uint32_t value);

    uint32_t& sentTS() OMG_NOEXCEPT; 
    const uint32_t& sentTS() const OMG_NOEXCEPT;
    void sentTS(uint32_t value);

    bool operator == (const Schedule& other_) const;
    bool operator != (const Schedule& other_) const;

    void swap(Schedule& other_) OMG_NOEXCEPT ;

  private:

    bool m_scheduled_;
    uint32_t m_until_;
    uint32_t m_sentTS_;

};

inline void swap(Schedule& a, Schedule& b)  OMG_NOEXCEPT 
{
    a.swap(b);
}

NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const Schedule& sample);

namespace dds { 
    namespace topic {

        template<>
        struct topic_type_name<Schedule> {
            NDDSUSERDllExport static std::string value() {
                return "Schedule";
            }
        };

        template<>
        struct is_topic_type<Schedule> : public dds::core::true_type {};

        template<>
        struct topic_type_support<Schedule> {
            NDDSUSERDllExport 
            static void register_type(
                dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, const Schedule& sample);

            NDDSUSERDllExport 
            static void from_cdr_buffer(Schedule& sample, const std::vector<char>& buffer);

            NDDSUSERDllExport 
            static void reset_sample(Schedule& sample);

            NDDSUSERDllExport 
            static void allocate_sample(Schedule& sample, int, int);

            static const rti::topic::TypePluginKind::type type_plugin_kind = 
            rti::topic::TypePluginKind::STL;
        };

    }
}

namespace rti { 
    namespace topic {
        template<>
        struct dynamic_type<Schedule> {
            typedef dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility<Schedule> {
            static const dds::core::xtypes::ExtensibilityKind::type kind =
            dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

    }
}

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif // Schedule_1325351769_hpp

