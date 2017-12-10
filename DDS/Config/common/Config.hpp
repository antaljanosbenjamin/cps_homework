

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from Config.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef Config_1471124070_hpp
#define Config_1471124070_hpp

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

class NDDSUSERDllExport Config {

  public:
    Config();
    Config(
        double maxTemperature,
        uint32_t maxPollution,
        uint32_t minHumidity,
        uint32_t maxHumidity);

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    Config (Config&&) = default;
    Config& operator=(Config&&) = default;
    Config& operator=(const Config&) = default;
    Config(const Config&) = default;
    #else
    Config(Config&& other_) OMG_NOEXCEPT;  
    Config& operator=(Config&&  other_) OMG_NOEXCEPT;
    #endif
    #endif 

    double& maxTemperature() OMG_NOEXCEPT; 
    const double& maxTemperature() const OMG_NOEXCEPT;
    void maxTemperature(double value);

    uint32_t& maxPollution() OMG_NOEXCEPT; 
    const uint32_t& maxPollution() const OMG_NOEXCEPT;
    void maxPollution(uint32_t value);

    uint32_t& minHumidity() OMG_NOEXCEPT; 
    const uint32_t& minHumidity() const OMG_NOEXCEPT;
    void minHumidity(uint32_t value);

    uint32_t& maxHumidity() OMG_NOEXCEPT; 
    const uint32_t& maxHumidity() const OMG_NOEXCEPT;
    void maxHumidity(uint32_t value);

    bool operator == (const Config& other_) const;
    bool operator != (const Config& other_) const;

    void swap(Config& other_) OMG_NOEXCEPT ;

  private:

    double m_maxTemperature_;
    uint32_t m_maxPollution_;
    uint32_t m_minHumidity_;
    uint32_t m_maxHumidity_;

};

inline void swap(Config& a, Config& b)  OMG_NOEXCEPT 
{
    a.swap(b);
}

NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const Config& sample);

namespace dds { 
    namespace topic {

        template<>
        struct topic_type_name<Config> {
            NDDSUSERDllExport static std::string value() {
                return "Config";
            }
        };

        template<>
        struct is_topic_type<Config> : public dds::core::true_type {};

        template<>
        struct topic_type_support<Config> {
            NDDSUSERDllExport 
            static void register_type(
                dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, const Config& sample);

            NDDSUSERDllExport 
            static void from_cdr_buffer(Config& sample, const std::vector<char>& buffer);

            NDDSUSERDllExport 
            static void reset_sample(Config& sample);

            NDDSUSERDllExport 
            static void allocate_sample(Config& sample, int, int);

            static const rti::topic::TypePluginKind::type type_plugin_kind = 
            rti::topic::TypePluginKind::STL;
        };

    }
}

namespace rti { 
    namespace topic {
        template<>
        struct dynamic_type<Config> {
            typedef dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility<Config> {
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

#endif // Config_1471124070_hpp

