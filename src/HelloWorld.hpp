

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from HelloWorld.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef HelloWorld_1436886690_hpp
#define HelloWorld_1436886690_hpp

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

static const int32_t HELLODDS_MAX_PAYLOAD_SIZE = 8192;

static const int32_t HELLODDS_MAX_STRING_SIZE = 64;

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
// On Windows, dll-export template instantiations of standard types used by
// other dll-exported types
template class NDDSUSERDllExport std::allocator<uint8_t>;
template class NDDSUSERDllExport std::vector<uint8_t >;
#endif
class NDDSUSERDllExport HelloWorld {

  public:
    HelloWorld();
    HelloWorld(
        const std::string& prefix,
        int32_t sampleId,
        const rti::core::bounded_sequence<uint8_t, (HELLODDS_MAX_PAYLOAD_SIZE)>& payload);

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    HelloWorld (HelloWorld&&) = default;
    HelloWorld& operator=(HelloWorld&&) = default;
    HelloWorld& operator=(const HelloWorld&) = default;
    HelloWorld(const HelloWorld&) = default;
    #else
    HelloWorld(HelloWorld&& other_) OMG_NOEXCEPT;  
    HelloWorld& operator=(HelloWorld&&  other_) OMG_NOEXCEPT;
    #endif
    #endif 

    std::string& prefix() OMG_NOEXCEPT; 
    const std::string& prefix() const OMG_NOEXCEPT;
    void prefix(const std::string& value);

    int32_t& sampleId() OMG_NOEXCEPT; 
    const int32_t& sampleId() const OMG_NOEXCEPT;
    void sampleId(int32_t value);

    rti::core::bounded_sequence<uint8_t, (HELLODDS_MAX_PAYLOAD_SIZE)>& payload() OMG_NOEXCEPT; 
    const rti::core::bounded_sequence<uint8_t, (HELLODDS_MAX_PAYLOAD_SIZE)>& payload() const OMG_NOEXCEPT;
    void payload(const rti::core::bounded_sequence<uint8_t, (HELLODDS_MAX_PAYLOAD_SIZE)>& value);

    bool operator == (const HelloWorld& other_) const;
    bool operator != (const HelloWorld& other_) const;

    void swap(HelloWorld& other_) OMG_NOEXCEPT ;

  private:

    std::string m_prefix_;
    int32_t m_sampleId_;
    rti::core::bounded_sequence<uint8_t, (HELLODDS_MAX_PAYLOAD_SIZE)> m_payload_;

};

inline void swap(HelloWorld& a, HelloWorld& b)  OMG_NOEXCEPT 
{
    a.swap(b);
}

NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const HelloWorld& sample);

namespace dds { 
    namespace topic {

        template<>
        struct topic_type_name<HelloWorld> {
            NDDSUSERDllExport static std::string value() {
                return "HelloWorld";
            }
        };

        template<>
        struct is_topic_type<HelloWorld> : public dds::core::true_type {};

        template<>
        struct topic_type_support<HelloWorld> {
            NDDSUSERDllExport 
            static void register_type(
                dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, const HelloWorld& sample);

            NDDSUSERDllExport 
            static void from_cdr_buffer(HelloWorld& sample, const std::vector<char>& buffer);

            NDDSUSERDllExport 
            static void reset_sample(HelloWorld& sample);

            NDDSUSERDllExport 
            static void allocate_sample(HelloWorld& sample, int, int);

            static const rti::topic::TypePluginKind::type type_plugin_kind = 
            rti::topic::TypePluginKind::STL;
        };

    }
}

namespace rti { 
    namespace topic {

        template<>
        struct dynamic_type<HelloWorld> {
            typedef dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility<HelloWorld> {
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

#endif // HelloWorld_1436886690_hpp

