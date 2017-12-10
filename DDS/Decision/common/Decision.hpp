

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from Decision.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef Decision_839300842_hpp
#define Decision_839300842_hpp

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

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif
#include "DDS/Weather/common/Weather.hpp"
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif
#include "DDS/Config/common/Config.hpp"
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif
#include "DDS/Schedule/common/Schedule.hpp"
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif
#include "DDS/Humidity/common/UvegHaz.hpp"
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif
struct Decision_def {
    enum type {
        CLOSE,      
        OPEN     
    };
    static type get_default(){ return CLOSE;}
};

typedef dds::core::safe_enum<Decision_def> Decision;
NDDSUSERDllExport std::ostream& operator << (std::ostream& o,const Decision& sample);

class NDDSUSERDllExport DecisionInfo {

  public:
    DecisionInfo();
    DecisionInfo(
        uint32_t decisionTS,
        const Decision& decision,
        const Config& config,
        const Weather& lastWeather,
        const Schedule& lastSchedule,
        const UvegHaz& lastHumidity);

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    DecisionInfo (DecisionInfo&&) = default;
    DecisionInfo& operator=(DecisionInfo&&) = default;
    DecisionInfo& operator=(const DecisionInfo&) = default;
    DecisionInfo(const DecisionInfo&) = default;
    #else
    DecisionInfo(DecisionInfo&& other_) OMG_NOEXCEPT;  
    DecisionInfo& operator=(DecisionInfo&&  other_) OMG_NOEXCEPT;
    #endif
    #endif 

    uint32_t& decisionTS() OMG_NOEXCEPT; 
    const uint32_t& decisionTS() const OMG_NOEXCEPT;
    void decisionTS(uint32_t value);

    Decision& decision() OMG_NOEXCEPT; 
    const Decision& decision() const OMG_NOEXCEPT;
    void decision(const Decision& value);

    Config& config() OMG_NOEXCEPT; 
    const Config& config() const OMG_NOEXCEPT;
    void config(const Config& value);

    Weather& lastWeather() OMG_NOEXCEPT; 
    const Weather& lastWeather() const OMG_NOEXCEPT;
    void lastWeather(const Weather& value);

    Schedule& lastSchedule() OMG_NOEXCEPT; 
    const Schedule& lastSchedule() const OMG_NOEXCEPT;
    void lastSchedule(const Schedule& value);

    UvegHaz& lastHumidity() OMG_NOEXCEPT; 
    const UvegHaz& lastHumidity() const OMG_NOEXCEPT;
    void lastHumidity(const UvegHaz& value);

    bool operator == (const DecisionInfo& other_) const;
    bool operator != (const DecisionInfo& other_) const;

    void swap(DecisionInfo& other_) OMG_NOEXCEPT ;

  private:

    uint32_t m_decisionTS_;
    Decision m_decision_;
    Config m_config_;
    Weather m_lastWeather_;
    Schedule m_lastSchedule_;
    UvegHaz m_lastHumidity_;

};

inline void swap(DecisionInfo& a, DecisionInfo& b)  OMG_NOEXCEPT 
{
    a.swap(b);
}

NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const DecisionInfo& sample);

namespace dds { 
    namespace topic {

        template<>
        struct topic_type_name<DecisionInfo> {
            NDDSUSERDllExport static std::string value() {
                return "DecisionInfo";
            }
        };

        template<>
        struct is_topic_type<DecisionInfo> : public dds::core::true_type {};

        template<>
        struct topic_type_support<DecisionInfo> {
            NDDSUSERDllExport 
            static void register_type(
                dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, const DecisionInfo& sample);

            NDDSUSERDllExport 
            static void from_cdr_buffer(DecisionInfo& sample, const std::vector<char>& buffer);

            NDDSUSERDllExport 
            static void reset_sample(DecisionInfo& sample);

            NDDSUSERDllExport 
            static void allocate_sample(DecisionInfo& sample, int, int);

            static const rti::topic::TypePluginKind::type type_plugin_kind = 
            rti::topic::TypePluginKind::STL;
        };

    }
}

namespace rti { 
    namespace topic {

        template<>
        struct dynamic_type<Decision> {
            typedef dds::core::xtypes::EnumType type;
            NDDSUSERDllExport static const dds::core::xtypes::EnumType& get();
        };

        template <>
        struct extensibility<Decision> {
            static const dds::core::xtypes::ExtensibilityKind::type kind =
            dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        template<>
        struct dynamic_type<DecisionInfo> {
            typedef dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility<DecisionInfo> {
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

#endif // Decision_839300842_hpp

