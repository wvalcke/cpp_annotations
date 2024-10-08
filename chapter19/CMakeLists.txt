cmake_minimum_required(VERSION 3.20)

add_executable(accumulate)
target_sources(accumulate PRIVATE accumulate.cc)
target_compile_features(accumulate PRIVATE cxx_std_23)

add_executable(adjacentdifference)
target_sources(adjacentdifference PRIVATE adjacentdifference.cc)
target_compile_features(adjacentdifference PRIVATE cxx_std_23)

add_executable(adjacentfind)
target_sources(adjacentfind PRIVATE adjacentfind.cc)
target_compile_features(adjacentfind PRIVATE cxx_std_23)

add_executable(allof)
target_sources(allof PRIVATE allof.cc)
target_compile_features(allof PRIVATE cxx_std_23)

add_executable(beginend)
target_sources(beginend PRIVATE beginend.cc)
target_compile_features(beginend PRIVATE cxx_std_23)

add_executable(binarysearch)
target_sources(binarysearch PRIVATE binarysearch.cc)
target_compile_features(binarysearch PRIVATE cxx_std_23)

add_executable(copy_copyif)
target_sources(copy_copyif PRIVATE copy.cc)
target_compile_features(copy_copyif PRIVATE cxx_std_23)

add_executable(copybackward)
target_sources(copybackward PRIVATE copybackward.cc)
target_compile_features(copybackward PRIVATE cxx_std_23)

add_executable(count_countif)
target_sources(count_countif PRIVATE count.cc)
target_compile_features(count_countif PRIVATE cxx_std_23)

add_executable(equal)
target_sources(equal PRIVATE equal.cc)
target_compile_features(equal PRIVATE cxx_std_23)

add_executable(equalrange)
target_sources(equalrange PRIVATE equalrange.cc)
target_compile_features(equalrange PRIVATE cxx_std_23)

add_executable(exchange)
target_sources(exchange PRIVATE exchange.cc)
target_compile_features(exchange PRIVATE cxx_std_23)

add_executable(fill)
target_sources(fill PRIVATE fill.cc)
target_compile_features(fill PRIVATE cxx_std_23)

add_executable(find)
target_sources(find PRIVATE find.cc)
target_compile_features(find PRIVATE cxx_std_23)

add_executable(findend)
target_sources(findend PRIVATE findend.cc)
target_compile_features(findend PRIVATE cxx_std_23)

add_executable(findfirstof)
target_sources(findfirstof PRIVATE findfirstof.cc)
target_compile_features(findfirstof PRIVATE cxx_std_23)

add_executable(foreach)
target_sources(foreach PRIVATE foreach.cc)
target_compile_features(foreach PRIVATE cxx_std_23)

add_executable(foreachclass)
target_sources(foreachclass PRIVATE foreachclass.cc)
target_compile_features(foreachclass PRIVATE cxx_std_23)

add_executable(generate)
target_sources(generate PRIVATE generate.cc)
target_compile_features(generate PRIVATE cxx_std_23)

add_executable(includes)
target_sources(includes PRIVATE includes.cc)
target_compile_features(includes PRIVATE cxx_std_23)

add_executable(innerproduct)
target_sources(innerproduct PRIVATE innerproduct.cc)
target_compile_features(innerproduct PRIVATE cxx_std_23)

add_executable(inplacemerge)
target_sources(inplacemerge PRIVATE inplacemerge.cc)
target_compile_features(inplacemerge PRIVATE cxx_std_23)

add_executable(iota)
target_sources(iota PRIVATE iota.cc)
target_compile_features(iota PRIVATE cxx_std_23)

add_executable(ispartitioned)
target_sources(ispartitioned PRIVATE ispartitioned.cc)
target_compile_features(ispartitioned PRIVATE cxx_std_23)

add_executable(ispermutation)
target_sources(ispermutation PRIVATE ispermutation.cc)
target_compile_features(ispermutation PRIVATE cxx_std_23)

add_executable(issorted)
target_sources(issorted PRIVATE issorted.cc)
target_compile_features(issorted PRIVATE cxx_std_23)

add_executable(issorteduntil)
target_sources(issorteduntil PRIVATE issorteduntil.cc)
target_compile_features(issorteduntil PRIVATE cxx_std_23)

add_executable(iterswap)
target_sources(iterswap PRIVATE iterswap.cc)
target_compile_features(iterswap PRIVATE cxx_std_23)

add_executable(lexicographicalcompare)
target_sources(lexicographicalcompare PRIVATE lexicographicalcompare.cc)
target_compile_features(lexicographicalcompare PRIVATE cxx_std_23)

add_executable(lowerbound)
target_sources(lowerbound PRIVATE lowerbound.cc)
target_compile_features(lowerbound PRIVATE cxx_std_23)

add_executable(max)
target_sources(max PRIVATE max.cc)
target_compile_features(max PRIVATE cxx_std_23)

add_executable(maxelement)
target_sources(maxelement PRIVATE maxelement.cc)
target_compile_features(maxelement PRIVATE cxx_std_23)

add_executable(merge)
target_sources(merge PRIVATE merge.cc)
target_compile_features(merge PRIVATE cxx_std_23)

add_executable(minmax)
target_sources(minmax PRIVATE minmax.cc)
target_compile_features(minmax PRIVATE cxx_std_23)

add_executable(mismatch)
target_sources(mismatch PRIVATE mismatch.cc)
target_compile_features(mismatch PRIVATE cxx_std_23)

add_executable(move)
target_sources(move PRIVATE move.cc)
target_compile_features(move PRIVATE cxx_std_23)

add_executable(nextpermutation)
target_sources(nextpermutation PRIVATE nextpermutation.cc)
target_compile_features(nextpermutation PRIVATE cxx_std_23)

add_executable(nthelement)
target_sources(nthelement PRIVATE nthelement.cc)
target_compile_features(nthelement PRIVATE cxx_std_23)

add_executable(partialsort)
target_sources(partialsort PRIVATE partialsort.cc)
target_compile_features(partialsort PRIVATE cxx_std_23)

add_executable(partialsum)
target_sources(partialsum PRIVATE partialsum.cc)
target_compile_features(partialsum PRIVATE cxx_std_23)

add_executable(partition)
target_sources(partition PRIVATE partition.cc)
target_compile_features(partition PRIVATE cxx_std_23)

add_executable(partitioncopy)
target_sources(partitioncopy PRIVATE partitioncopy.cc)
target_compile_features(partitioncopy PRIVATE cxx_std_23)

add_executable(reduce)
target_sources(reduce PRIVATE reduce.cc)
target_compile_features(reduce PRIVATE cxx_std_23)
target_link_libraries(reduce PRIVATE TBB::tbb)

add_executable(remove)
target_sources(remove PRIVATE remove.cc)
target_compile_features(remove PRIVATE cxx_std_23)

add_executable(replace)
target_sources(replace PRIVATE replace.cc)
target_compile_features(replace PRIVATE cxx_std_23)

add_executable(replacecopy)
target_sources(replacecopy PRIVATE replacecopy.cc)
target_compile_features(replacecopy PRIVATE cxx_std_23)

add_executable(replacecopyif)
target_sources(replacecopyif PRIVATE replacecopyif.cc)
target_compile_features(replacecopyif PRIVATE cxx_std_23)

add_executable(reverse)
target_sources(reverse PRIVATE reverse.cc)
target_compile_features(reverse PRIVATE cxx_std_23)

install(TARGETS accumulate adjacentdifference adjacentfind allof beginend
    binarysearch copy_copyif copybackward count_countif equal equalrange exchange
    fill find findend findfirstof foreach foreachclass generate includes innerproduct
    inplacemerge iota ispartitioned ispermutation issorted issorteduntil
    iterswap lexicographicalcompare lowerbound max maxelement merge minmax
    mismatch move nextpermutation nthelement partialsort partialsum partition
    partitioncopy reduce remove replace replacecopy replacecopyif reverse
DESTINATION chapter19)
#install(FILES double.bin flags.txt nonewline.txt DESTINATION chapter3)
