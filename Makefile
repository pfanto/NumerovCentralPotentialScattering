CPP = g++
RM = rm
CPPFLAGS = -I/~/CPPLibs/boost_1_67_0/ # should replace this with link to boost library, if using a different C++ library.
PROG = phaseshifts
PROGOBJS = phaseshifts.o scattering.o potentials.o numerov.o
LIBOBJS = writeout.o

make: $(PROG)

phaseshifts: $(PROGOBJS) $(LIBOBJS)
	$(CPP) $(PROGOBJS) $(LIBOBJS) $(CPPFLAGS) -o phaseshifts

clean:
	$(RM) $(PROG) $(PROGOBJS)

numerov.o: numerov.hpp

potentials.o: potentials.hpp

scattering.o: scattering.hpp potentials.hpp numerov.hpp writeout.hpp constant.hpp

phaseshifts.o: phaseshifts.hpp scattering.hpp constant.hpp writeout.hpp

writeout.o: writeout.hpp

