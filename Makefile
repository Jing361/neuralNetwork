include Make.cfg

default:$(name)

$(name):$(OBJECTS)
	$(CC) $+ $(FLAGS) -o $@

-include $(DEPENDS)

# more complicated dependency computation, so all prereqs listed
# will also become command-less, prereq-less targets
#   sed:    strip the target (everything before colon)
#   sed:    remove any continuation backslashes
#   fmt -1: list words one per line
#   sed:    strip leading spaces
#   sed:    add trailing colons
$(OBJECTDIR)/%.o:
	$(CC) -c $(SOURCEDIR)/$*.cc $(FLAGS) -o $@
	$(CC) -MM $(FLAGS) $(SOURCEDIR)/$*.cc > $(DEPENDDIR)/$*.d
	@mv -f $(DEPENDDIR)/$*.d $(DEPENDDIR)/$*.d.tmp
	@sed -e 's|.*:|$(OBJECTDIR)/$*.o:|' < $(DEPENDDIR)/$*.d.tmp > $(DEPENDDIR)/$*.d
	@sed -e 's/.*://' -e 's/\\$$//' < $(DEPENDDIR)/$*.d.tmp | fmt -1 | \
	  sed -e 's/^ *//' -e 's/$$/:/' >> $(DEPENDDIR)/$*.d
	@rm -f $(DEPENDDIR)/$*.d.tmp

clean:
	rm $(OBJECTDIR)/*.o *.exe* $(DEPENDDIR)/*.d

.PHONY:clean default

#file partially written based on information from:
#http://scottmcpeak.com/autodepend/autodepend.html

