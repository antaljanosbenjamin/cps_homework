

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from UvegHaz.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef UvegHaz_512309000_hpp
#define UvegHaz_512309000_hpp

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

class NDDSUSERDllExport UvegHaz {

  public:
    UvegHaz();
    UvegHaz(
        const std::string& ID,
        double Value,
        int32_t TimeStamp);

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    UvegHaz (UvegHaz&&) = default;
    UvegHaz& operator=(UvegHaz&&) = default;
    UvegHaz& operator=(const UvegHaz&) = default;
    UvegHaz(const UvegHaz&) = default;
    #else
    UvegHaz(UvegHaz&& other_) OMG_NOEXCEPT;  
    UvegHaz& operator=(UvegHaz&&  other_) OMG_NOEXCEPT;
    #endif
    #endif 

    std::string& ID() OMG_NOEXCEPT; 
    const std::string& ID() const OMG_NOEXCEPT;
    void ID(const std::string& value);

    double& Value() OMG_NOEXCEPT; 
    const double& Value() const OMG_NOEXCEPT;
    void Value(double value);

    int32_t& TimeStamp() OMG_NOEXCEPT; 
    const int32_t& TimeStamp() const OMG_NOEXCEPT;
    void TimeStamp(int32_t value);

    bool operator == (const UvegHaz& other_) const;
    bool operator != (const UvegHaz& other_) const;

    void swap(UvegHaz& other_) OMG_NOEXCEPT ;

  private:

    std::string m_ID_;
    double m_Value_;
    int32_t m_TimeStamp_;

};

inline void swap(UvegHaz& a, UvegHaz& b)  OMG_NOEXCEPT 
{
    a.swap(b);
}

NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const UvegHaz& sample);

namespace dds { 
    namespace topic {

        template<>
        struct topic_type_name<UvegHaz> {
            NDDSUSERDllExport static std::string value() {
                return "UvegHaz";
            }
        };

        template<>
        struct is_topic_type<UvegHaz> : public dds::core::true_type {};

        template<>
        struct topic_type_support<UvegHaz> {
            NDDSUSERDllExport 
            static void register_type(
                dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, const UvegHaz& sample);

            NDDSUSERDllExport 
            static void from_cdr_buffer(UvegHaz& sample, const std::vector<char>& buffer);

            NDDSUSERDllExport 
            static void reset_sample(UvegHaz& sample);

            NDDSUSERDllExport 
            static void allocate_sample(UvegHaz& sample, int, int);

            static const rti::topic::TypePluginKind::type type_plugin_kind = 
            rti::topic::TypePluginKind::STL;
        };

    }
}

namespace rti { 
    namespace topic {
        template<>
        struct dynamic_type<UvegHaz> {
            typedef dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility<UvegHaz> {
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

#endif // UvegHaz_512309000_hpp

