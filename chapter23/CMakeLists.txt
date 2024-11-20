cmake_minimum_required(VERSION 3.20)

add_executable(basename2)
target_sources(basename2 PRIVATE basename2.cc)
target_compile_features(basename2 PRIVATE cxx_std_23)

add_executable(templatekeyword)
target_sources(templatekeyword PRIVATE templatekeyword.cc)
target_compile_features(templatekeyword PRIVATE cxx_std_23)

add_executable(templatekeyword2)
target_sources(templatekeyword2 PRIVATE templatekeyword2.cc)
target_compile_features(templatekeyword2 PRIVATE cxx_std_23)

add_executable(templatekeyword3)
target_sources(templatekeyword3 PRIVATE templatekeyword3.cc)
target_compile_features(templatekeyword3 PRIVATE cxx_std_23)

add_executable(templatekeyword4)
target_sources(templatekeyword4 PRIVATE templatekeyword4.cc)
target_compile_features(templatekeyword4 PRIVATE cxx_std_23)

add_executable(inttype)
target_sources(inttype PRIVATE inttype.cc)
target_compile_features(inttype PRIVATE cxx_std_23)

add_executable(storagepoly)
target_sources(storagepoly PRIVATE storagepoly.cc)
target_compile_features(storagepoly PRIVATE cxx_std_23)

add_executable(storagepoly2)
target_sources(storagepoly2 PRIVATE storagepoly2.cc)
target_compile_features(storagepoly2 PRIVATE cxx_std_23)

add_executable(factorial)
target_sources(factorial PRIVATE factorial.cc)
target_compile_features(factorial PRIVATE cxx_std_23)

add_executable(miles)
target_sources(miles PRIVATE miles.cc)
target_compile_features(miles PRIVATE cxx_std_23)

add_executable(alloctest)
target_sources(alloctest PRIVATE alloctest.cc)
target_compile_features(alloctest PRIVATE cxx_std_23)

add_executable(storage)
target_sources(storage PRIVATE storage.cc)
target_compile_features(storage PRIVATE cxx_std_23)

add_executable(structbypolicy)
target_sources(structbypolicy PRIVATE structbypolicy.cc)
target_compile_features(structbypolicy PRIVATE cxx_std_23)

add_executable(aliastemplate)
target_sources(aliastemplate PRIVATE aliastemplate.cc)
target_compile_features(aliastemplate PRIVATE cxx_std_23)

add_executable(basictraits)
target_sources(basictraits PRIVATE basictraits.cc)
target_compile_features(basictraits PRIVATE cxx_std_23)

add_executable(traitstest)
target_sources(traitstest PRIVATE traitstest.cc)
target_compile_features(traitstest PRIVATE cxx_std_23)

add_subdirectory(errcode)

add_executable(typetype)
target_sources(typetype PRIVATE typetype.cc)
target_compile_features(typetype PRIVATE cxx_std_23)

add_executable(enableif)
target_sources(enableif PRIVATE enableif.cc)
target_compile_features(enableif PRIVATE cxx_std_23)

add_executable(conversion)
target_sources(conversion PRIVATE conversion.cc)
target_compile_features(conversion PRIVATE cxx_std_23)

add_executable(variadiclistsize)
target_sources(variadiclistsize PRIVATE variadiclistsize.cc)
target_compile_features(variadiclistsize PRIVATE cxx_std_23)

add_executable(typelistlength)
target_sources(typelistlength PRIVATE typelistlength.cc)
target_compile_features(typelistlength PRIVATE cxx_std_23)

add_executable(listsearch)
target_sources(listsearch PRIVATE listsearch.cc)
target_compile_features(listsearch PRIVATE cxx_std_23)

add_executable(usingtest)
target_sources(usingtest PRIVATE usingtest.cc)
target_compile_features(usingtest PRIVATE cxx_std_23)

add_executable(multibase)
target_sources(multibase PRIVATE multibase.cc)
target_compile_features(multibase PRIVATE cxx_std_23)

add_executable(exprtempl)
target_sources(exprtempl PRIVATE exprtempl.cc)
target_compile_features(exprtempl PRIVATE cxx_std_23)

add_executable(exprtempl2)
target_sources(exprtempl2 PRIVATE exprtempl2.cc)
target_compile_features(exprtempl2 PRIVATE cxx_std_23)

add_executable(exprtempl3)
target_sources(exprtempl3 PRIVATE exprtempl3.cc)
target_compile_features(exprtempl3 PRIVATE cxx_std_23)

add_executable(exprtempl4)
target_sources(exprtempl4 PRIVATE exprtempl4.cc)
target_compile_features(exprtempl4 PRIVATE cxx_std_23)

add_executable(exprtempl5)
target_sources(exprtempl5 PRIVATE exprtempl5.cc)
target_compile_features(exprtempl5 PRIVATE cxx_std_23)

add_executable(exprtempl6)
target_sources(exprtempl6 PRIVATE exprtempl6.cc)
target_compile_features(exprtempl6 PRIVATE cxx_std_23)

add_executable(exprtempl7)
target_sources(exprtempl7 PRIVATE exprtempl7.cc)
target_compile_features(exprtempl7 PRIVATE cxx_std_23)

add_executable(exprtempl8)
target_sources(exprtempl8 PRIVATE exprtempl8.cc)
target_compile_features(exprtempl8 PRIVATE cxx_std_23)

add_executable(exprtempl9)
target_sources(exprtempl9 PRIVATE exprtempl9.cc)
target_compile_features(exprtempl9 PRIVATE cxx_std_23)

add_executable(exprtempl10)
target_sources(exprtempl10 PRIVATE exprtempl10.cc)
target_compile_features(exprtempl10 PRIVATE cxx_std_23)

add_executable(exprtempl11)
target_sources(exprtempl11 PRIVATE exprtempl11.cc)
target_compile_features(exprtempl11 PRIVATE cxx_std_23)

add_executable(simpleconcept)
target_sources(simpleconcept PRIVATE simpleconcept.cc)
target_compile_features(simpleconcept PRIVATE cxx_std_23)

add_executable(typeconcept)
target_sources(typeconcept PRIVATE typeconcept.cc)
target_compile_features(typeconcept PRIVATE cxx_std_23)

add_executable(returnconcept)
target_sources(returnconcept PRIVATE returnconcept.cc)
target_compile_features(returnconcept PRIVATE cxx_std_23)

add_executable(returnconcept2)
target_sources(returnconcept2 PRIVATE returnconcept2.cc)
target_compile_features(returnconcept2 PRIVATE cxx_std_23)

add_executable(predefconcept)
target_sources(predefconcept PRIVATE predefconcept.cc)
target_compile_features(predefconcept PRIVATE cxx_std_23)

add_executable(conceptstringret)
target_sources(conceptstringret PRIVATE conceptstringret.cc)
target_compile_features(conceptstringret PRIVATE cxx_std_23)

add_executable(convertconcept)
target_sources(convertconcept PRIVATE convertconcept.cc)
target_compile_features(convertconcept PRIVATE cxx_std_23)

add_executable(constructibleconcept)
target_sources(constructibleconcept PRIVATE constructibleconcept.cc)
target_compile_features(constructibleconcept PRIVATE cxx_std_23)

add_executable(invokableconcept)
target_sources(invokableconcept PRIVATE invokableconcept.cc)
target_compile_features(invokableconcept PRIVATE cxx_std_23)

add_executable(predicateconcept)
target_sources(predicateconcept PRIVATE predicateconcept.cc)
target_compile_features(predicateconcept PRIVATE cxx_std_23)

add_executable(relationconcept)
target_sources(relationconcept PRIVATE relationconcept.cc)
target_compile_features(relationconcept PRIVATE cxx_std_23)

add_executable(sizesum)
target_sources(sizesum PRIVATE sizesum.cc)
target_compile_features(sizesum PRIVATE cxx_std_23)

add_executable(allintegralconcept)
target_sources(allintegralconcept PRIVATE allintegralconcept.cc)
target_compile_features(allintegralconcept PRIVATE cxx_std_23)

add_executable(addableconcept)
target_sources(addableconcept PRIVATE addableconcept.cc)
target_compile_features(addableconcept PRIVATE cxx_std_23)

add_executable(partialconcept)
target_sources(partialconcept PRIVATE partialconcept.cc)
target_compile_features(partialconcept PRIVATE cxx_std_23)
add_executable(selectfromtypelist)
target_sources(selectfromtypelist PRIVATE selectfromtypelist.cc)
target_compile_features(selectfromtypelist PRIVATE cxx_std_23)

add_executable(prefixappendtypelist)
target_sources(prefixappendtypelist PRIVATE prefixappendtypelist.cc)
target_compile_features(prefixappendtypelist PRIVATE cxx_std_23)

add_executable(erasetypelist)
target_sources(erasetypelist PRIVATE erasetypelist.cc)
target_compile_features(erasetypelist PRIVATE cxx_std_23)

install(TARGETS basename2 templatekeyword templatekeyword2 templatekeyword3 
    templatekeyword4 inttype
    storagepoly storagepoly2 factorial miles alloctest storage structbypolicy
    aliastemplate basictraits traitstest typetype enableif conversion variadiclistsize
    typelistlength listsearch usingtest multibase exprtempl exprtempl2 exprtempl3
    exprtempl4 exprtempl5 exprtempl6 exprtempl7 exprtempl8 exprtempl9
    exprtempl10 exprtempl11 simpleconcept typeconcept returnconcept returnconcept2
    predefconcept conceptstringret convertconcept constructibleconcept invokableconcept
    predicateconcept relationconcept sizesum allintegralconcept addableconcept
    partialconcept
    typelistlength listsearch selectfromtypelist prefixappendtypelist erasetypelist
DESTINATION chapter23)
