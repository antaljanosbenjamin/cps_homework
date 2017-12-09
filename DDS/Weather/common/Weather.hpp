

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from Weather.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef Weather_1793541657_hpp
#define Weather_1793541657_hpp

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

class NDDSUSERDllExport Weather {

  public:
    Weather();
    Weather(
        double temperature,
        rti::core::uint64 tempTS,
        int32_t pollution,
        rti::core::uint64 pollTS);

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    Weather (Weather&&) = default;
    Weather& operator=(Weather&&) = default;
    Weather& operator=(const Weather&) = default;
    Weather(const Weather&) = default;
    #else
    Weather(Weather&& other_) OMG_NOEXCEPT;  
    Weather& operator=(Weather&&  other_) OMG_NOEXCEPT;
    #endif
    #endif 

    double& temperature() OMG_NOEXCEPT; 
    const double& temperature() const OMG_NOEXCEPT;
    void temperature(double value);

    rti::core::uint64& tempTS() OMG_NOEXCEPT; 
    const rti::core::uint64& tempTS() const OMG_NOEXCEPT;
    void tempTS(rti::core::uint64 value);

    int32_t& pollution() OMG_NOEXCEPT; 
    const int32_t& pollution() const OMG_NOEXCEPT;
    void pollution(int32_t value);

    rti::core::uint64& pollTS() OMG_NOEXCEPT; 
    const rti::core::uint64& pollTS() const OMG_NOEXCEPT;
    void pollTS(rti::core::uint64 value);

    bool operator == (const Weather& other_) const;
    bool operator != (const Weather& other_) const;

    void swap(Weather& other_) OMG_NOEXCEPT ;

  private:

    double m_temperature_;
    rti::core::uint64 m_tempTS_;
    int32_t m_pollution_;
    rti::core::uint64 m_pollTS_;

};

inline void swap(Weather& a, Weather& b)  OMG_NOEXCEPT 
{
    a.swap(b);
}

NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const Weather& sample);

namespace dds { 
    namespace topic {

        template<>
        struct topic_type_name<Weather> {
            NDDSUSERDllExport static std::string value() {
                return "Weather";
            }
        };

        template<>
        struct is_topic_type<Weather> : public dds::core::true_type {};

        template<>
        struct topic_type_support<Weather> {
            NDDSUSERDllExport 
            static void register_type(
                dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, const Weather& sample);

            NDDSUSERDllExport 
            static void from_cdr_buffer(Weather& sample, const std::vector<char>& buffer);

            NDDSUSERDllExport 
            static void reset_sample(Weather& sample);

            NDDSUSERDllExport 
            static void allocate_sample(Weather& sample, int, int);

            static const rti::topic::TypePluginKind::type type_plugin_kind = 
            rti::topic::TypePluginKind::STL;
        };

    }
}

namespace rti { 
    namespace topic {
        template<>
        struct dynamic_type<Weather> {
            typedef dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility<Weather> {
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

#endif // Weather_1793541657_hpp

