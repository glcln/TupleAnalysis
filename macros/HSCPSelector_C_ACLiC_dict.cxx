// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dIiphcmIdatadIsafe1dIcmsdIgcoulondICMSSW_15_0_13_patch1dIsrcdITupleAnalysisdImacrosdIHSCPSelector_C_ACLiC_dict
#define R__NO_DEPRECATION

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "ROOT/RConfig.hxx"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "/iphc-data/safe1/cms/gcoulon/CMSSW_15_0_13_patch1/src/TupleAnalysis/macros/./HSCPSelector.C"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_HSCPSelector(void *p = nullptr);
   static void *newArray_HSCPSelector(Long_t size, void *p);
   static void delete_HSCPSelector(void *p);
   static void deleteArray_HSCPSelector(void *p);
   static void destruct_HSCPSelector(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::HSCPSelector*)
   {
      ::HSCPSelector *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::HSCPSelector >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("HSCPSelector", ::HSCPSelector::Class_Version(), "HSCPSelector.h", 25,
                  typeid(::HSCPSelector), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::HSCPSelector::Dictionary, isa_proxy, 4,
                  sizeof(::HSCPSelector) );
      instance.SetNew(&new_HSCPSelector);
      instance.SetNewArray(&newArray_HSCPSelector);
      instance.SetDelete(&delete_HSCPSelector);
      instance.SetDeleteArray(&deleteArray_HSCPSelector);
      instance.SetDestructor(&destruct_HSCPSelector);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::HSCPSelector*)
   {
      return GenerateInitInstanceLocal(static_cast<::HSCPSelector*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::HSCPSelector*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr HSCPSelector::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *HSCPSelector::Class_Name()
{
   return "HSCPSelector";
}

//______________________________________________________________________________
const char *HSCPSelector::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::HSCPSelector*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int HSCPSelector::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::HSCPSelector*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *HSCPSelector::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::HSCPSelector*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *HSCPSelector::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::HSCPSelector*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void HSCPSelector::Streamer(TBuffer &R__b)
{
   // Stream an object of class HSCPSelector.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(HSCPSelector::Class(),this);
   } else {
      R__b.WriteClassBuffer(HSCPSelector::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_HSCPSelector(void *p) {
      return  p ? new(p) ::HSCPSelector : new ::HSCPSelector;
   }
   static void *newArray_HSCPSelector(Long_t nElements, void *p) {
      return p ? new(p) ::HSCPSelector[nElements] : new ::HSCPSelector[nElements];
   }
   // Wrapper around operator delete
   static void delete_HSCPSelector(void *p) {
      delete (static_cast<::HSCPSelector*>(p));
   }
   static void deleteArray_HSCPSelector(void *p) {
      delete [] (static_cast<::HSCPSelector*>(p));
   }
   static void destruct_HSCPSelector(void *p) {
      typedef ::HSCPSelector current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::HSCPSelector

namespace {
  void TriggerDictionaryInitialization_HSCPSelector_C_ACLiC_dict_Impl() {
    static const char* headers[] = {
"./HSCPSelector.C",
nullptr
    };
    static const char* includePaths[] = {
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/lcg/root/6.32.13-3ea6c37f14e3f39c0c3ce338c09aec10/include",
"/iphc-data/safe1/cms/gcoulon/CMSSW_15_0_13_patch1/src",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/cms/cmssw-patch/CMSSW_15_0_13_patch1/src",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/mctester/1.25.1-e3621381b0ab3bbf621059a7f6cba8cb/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/hydjet2/2.4.4-cdab34d0a1a13f1415b5eb795b9c5f81/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/dd4hep/v01-29-00-bd1fa0b0545dfc8e6e668b6daf7f9111/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/rivet/4.0.2-ec6ae7fabd0f404f0f9f84e4005dfc80/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/lwtnn/2.14.1-5de3a9548344b26e4451ad907838024b/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/tauolapp/1.1.8-5ab06e9798ab285a134976a78de0cc19/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/starlight/r193-4299dc1b161e57f922e485fd167df6f2/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/sherpa/2.2.15-9d9c1bb6c73724b8e5d376e8a7b32028/include/SHERPA-MC",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/highfive/2.3.1-479b018a6678253d1ba4d3bd69839553/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/herwig7/7.2.2-f393fd81ce0068fb388e2ab6574ef077/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/pythia8/311-62f197bacb831a8defc23e576ff6b2ab/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/classlib/3.1.3-2827e9dbeb7dd2aced5a46b8a966dfab/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/geant4/11.2.2-52b9dc70f3ca8efebf82b291217bc6c2/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/alpaka/1.2.0-94afb7b501b1959f67f6fd74096328d0/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/xrootd/5.7.2-ea80ee0ca8d46f1e87201dd16c9b691f/include/xrootd/private",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/tkonlinesw/4.2.0-1_gcc7-94d84a23305e2f0c66475ec9e64dda5f/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/pcre2/10.36-cdcfcb112d100e048938c4777a0a1836/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/libungif/4.1.4-2f91a77bad1564f8547f5d13089fd857/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/libtiff/4.0.10-d510c78a51ec326b33bb71bb87e5fbf2/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/libpng/1.6.37-ac24a052f0764e050f1085e744b63e73/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/thepeg/2.2.2-2d68a4ff51961664ebbdae906fc34c82/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/frontier_client/2.10.2-424f23c2544a35dfa84598f1f15afcc6/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/pcre/8.43-2d141998cfe5424b8f7aff48035cc2da/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/zstd/1.5.2-c5e6a53d5921f82c7542f1a4c5fbcc3d/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/cms/vdt/0.4.3-4870967f2eba63db6db5f9d739812ca1/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/valgrind/3.24.0-cc012d7fe78884d4e0706577d85bee44/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/utm/utm_0.13.0-538b5f73297bbeaa6f489651b69024a0/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/sigcpp/3.2.0-822d85000b677f1f6fbe907af08d7c8c/include/sigc++-3.0",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/sqlite/3.36.0-6a61dda6b4338fb9b6c26060efd5fd9a/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/pacparser/1.4.2-d62b951e0455795e0d154beda504125a/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/oracle/19.11.0.0.0dbru-0ef9ee763c1e7a90d8c4515a5af97f0b/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/py3-numpy/1.24.3-4b3f1d182846dd5b8cdd065bebf4e7f2/c-api/core/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/meschach/1.2.pCMS1-79435924678a8cc522f783c34e3865d7/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/lz4/1.9.2-e478fcd3e5e191d5bb4ade190474ad76/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/libuuid/2.34-27ce4c3579b5b1de2808ea9c4cd8ed29/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/libjpeg-turbo/2.0.2-3cab08429be43a78d2ecd1c6598ee750/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/ktjet/1.06-0c32371d0b63d85c811afb5ccda85c86/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/jemalloc-prof/5.3.0-75ab9431f9b38624b64e8680404206c5/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/jemalloc-debug/5.3.0-4144d7f94ef06dc82cab21306f98c999/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/jemalloc/5.3.0-0d50beec355425ed72b8a6798b9a125f/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/hls/2025.05-4da036171b10090d7d21e15c49bb27a1/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/madgraph5amcatnlo/2.7.3-da2c436690364e8f2255e2d0cd1da996",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/heppdt/3.04.01-0ef13ec7c94f9af4e098178f31f8e22b/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/hector/1.3.4_patch1-d2fc5538362f8adb6603752040614198/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/protobuf/3.21.9-d5949ee2f313d8eb1bcc8de115b32a05/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/libunwind/1.8.1-master-beabc0e9d66c563126dd61440aa2c705/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/giflib/5.2.1-63b47ba870c324f0f780aad18786582a/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/gdbm/1.10-1f0ec10a142f21150eef9d32ba579779/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/freetype/2.10.0-0a3e7e7418f34ddc4d3b2760dcabc963/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/fftw3/3.3.8-5270bdf9998065b38f91e9aa053c73ec/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/fftjet/1.5.0-4c95f831c41530ec8fa31a87717d9e5b/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/fastjet/3.4.1-71044756ca7b67339b95a884df339811/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/xz/5.2.5-87b9f5597eaeb8b5e9cedb5d183d5089/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/lcg/root/6.32.13-3ea6c37f14e3f39c0c3ce338c09aec10/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/dcap/2.47.12-5739970a201e5ecc2d22619681b1a468/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/libxml2/2.9.10-c415f3b7eaab8ebdde4f72b236d004a0/include/libxml2",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/curl/7.79.0-d8c0d5017cfad573d276c56bd08114b8/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/cppunit/1.15.x-9c5e10ac1b9ff043c0e3d26ccceb0058/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/cms/coral/CORAL_2_3_21-28bb211575b543bd50ef41d852d167ff/include/LCG",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/cms/cmssw/CMSSW_15_0_13/src",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/cms/cmssw/CMSSW_15_0_13/include/el9_amd64_gcc12/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/pythia6/426-c430ea6f2967f65248af15c71e6c653e/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/lhapdf/6.4.0-e7c4b9323f96fa15c22775e405ec99ed/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/hepmc/2.06.10-262d73524c32528e87adc31a98f68d52/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/gsl/2.6-f7574c606b0ce57ff601d3ca9534cd01/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/xerces-c/3.1.3-c7b88eaa36d0408120f3c29826a04bf6/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/expat/2.4.8-b093687a482bf386f8f8c236c5b2efa2/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/zlib/1.2.13-d217cdbdd8d586e845e05946de2796be/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/vecgeom/v1.2.7-6ef41c1a0471ffb9768e0b73b7641584/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/vecgeom/v1.2.7-6ef41c1a0471ffb9768e0b73b7641584/include/VecGeom",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/clhep/2.4.7.1-00d95dad51c51a565a6a059e09321311/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/bz2lib/1.0.6-d065ccd79984efc6d4660f410e4c81de/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/tbb/v2021.9.0-923065ff62d6d3ff52c3b52f6657aed2/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/rocm/6.3.2-dd4ace0770f12ddb6078527b081d5a79/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/cuda/12.8.0-5a6d49e4693d62148340846b99d6a8e3/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/boost/1.80.0-71a9f99e945ddf5b85afd9761a632291/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/xgboost/1.7.5-a05d32b24fba11208da3df9807f8bb22/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/tinyxml2/6.2.0-f99ae2781d074227d47e8a3e7c8ec87e/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/rdma-core/57.0-64ae2718d6a4bf75db5a1783d67ff5dd/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/ittnotify/16.06.18-f963cc841dbf061b8143306db7c66b39/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/gosamcontrib/2.0-20180708-24ee63d96e0de928b2dd0a3fbddfd69d/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/eigen/3bb6a48d8c171cf20b5f8e48bfb4e424fbd4f79e-e265b266d2b30c1bebdd883980d0f9d0/include/eigen3",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/hepmc3/3.2.7-f10dce5b16f0246f8cac8378933b9681/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/external/fmt/10.2.1-e35fd1db5eb3abc8ac0452e8ee427196/include",
"/usr/local/include",
"/usr/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/lcg/root/6.32.13-3ea6c37f14e3f39c0c3ce338c09aec10/etc/",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/lcg/root/6.32.13-3ea6c37f14e3f39c0c3ce338c09aec10/etc//cling",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/lcg/root/6.32.13-3ea6c37f14e3f39c0c3ce338c09aec10/etc//cling/plugins/include",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/lcg/root/6.32.13-3ea6c37f14e3f39c0c3ce338c09aec10/include/",
"src",
"/data/cmsbld/jenkins/workspace/auto-builds/CMSSW_15_0_13-el9_amd64_gcc12/build/CMSSW_15_0_13-build/el9_amd64_gcc12/external/pcre/8.43-2d141998cfe5424b8f7aff48035cc2da/include",
"/data/cmsbld/jenkins/workspace/auto-builds/CMSSW_15_0_13-el9_amd64_gcc12/build/CMSSW_15_0_13-build/el9_amd64_gcc12/external/bz2lib/1.0.6-d065ccd79984efc6d4660f410e4c81de/include",
"/data/cmsbld/jenkins/workspace/auto-builds/CMSSW_15_0_13-el9_amd64_gcc12/build/CMSSW_15_0_13-build/el9_amd64_gcc12/external/xz/5.2.5-87b9f5597eaeb8b5e9cedb5d183d5089/include",
"/data/cmsbld/jenkins/workspace/auto-builds/CMSSW_15_0_13-el9_amd64_gcc12/build/CMSSW_15_0_13-build/el9_amd64_gcc12/external/zlib/1.2.13-d217cdbdd8d586e845e05946de2796be/include",
"/data/cmsbld/jenkins/workspace/auto-builds/CMSSW_15_0_13-el9_amd64_gcc12/build/CMSSW_15_0_13-build/el9_amd64_gcc12/lcg/root/6.32.13-3ea6c37f14e3f39c0c3ce338c09aec10/include/",
"/data/cmsbld/jenkins/workspace/auto-builds/CMSSW_15_0_13-el9_amd64_gcc12/build/CMSSW_15_0_13-build/tmp/BUILDROOT/7827e7c6dec5715dd85511c192975665/opt/cmssw/el9_amd64_gcc12/cms/cmssw/CMSSW_15_0_13/",
"/cvmfs/cms.cern.ch/el9_amd64_gcc12/lcg/root/6.32.13-3ea6c37f14e3f39c0c3ce338c09aec10/include/",
"/iphc-data/safe1/cms/gcoulon/CMSSW_15_0_13_patch1/src/TupleAnalysis/macros/",
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "HSCPSelector_C_ACLiC_dict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
class __attribute__((annotate("$clingAutoload$HSCPSelector.h")))  __attribute__((annotate("$clingAutoload$./HSCPSelector.C")))  HSCPSelector;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "HSCPSelector_C_ACLiC_dict dictionary payload"

#ifndef __ACLIC__
  #define __ACLIC__ 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "./HSCPSelector.C"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"", payloadCode, "@",
"C", payloadCode, "@",
"C_bckg2017", payloadCode, "@",
"C_bckg2018", payloadCode, "@",
"C_data2017", payloadCode, "@",
"C_data2018", payloadCode, "@",
"C_signal2017", payloadCode, "@",
"C_signal2018", payloadCode, "@",
"HSCPSelector", payloadCode, "@",
"HSCPSelector::fgIsA", payloadCode, "@",
"K", payloadCode, "@",
"K_bckg2017", payloadCode, "@",
"K_bckg2018", payloadCode, "@",
"K_data2017", payloadCode, "@",
"K_data2018", payloadCode, "@",
"K_signal2017", payloadCode, "@",
"K_signal2018", payloadCode, "@",
"deltaR", payloadCode, "@",
"year", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("HSCPSelector_C_ACLiC_dict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_HSCPSelector_C_ACLiC_dict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_HSCPSelector_C_ACLiC_dict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_HSCPSelector_C_ACLiC_dict() {
  TriggerDictionaryInitialization_HSCPSelector_C_ACLiC_dict_Impl();
}
