# Code generators used by CreateSelector.py.
#
# Each row of cfg/HSCPpreSelections.csv holds a selection label (first column) and the
# C++ boolean expression defining it (second column), written with the TTreeReader
# members of HSCPSelector and the candidate index i. A row whose label starts with #
# is skipped.

# check if a line or a work is commented
# meaning starting by a #
def IsCommented(label):
    return label.split()[0][0]=="#"

# Generate the prototype of a data function used for HSPC selection in the HSCPSelector class
# A label should be associated to the selection
def HSCPSelectorProto(label):
    #content for header file
    hcontent = "bool PassHSCPpresel_"+label+"(int hscpIndex);\n"
    return hcontent

# Generate a data function implementation used for HSPC selection in the HSCPSelector class
# A label should be associated to the selection
# Assume that instruction are already c++ instructions using TTreeReadValues or Arrays
def HSCPSelectorImpl(label, instruction):
    #content for C file
    content = "bool HSCPSelector::PassHSCPpresel_"+label+"(int i){\n"

    if (label == "CalibPseudoMET"):
        content+= "   if (i < 0) {\n"
        content+= "      cout << i << endl;\n"
        content+= "      return false;\n"
        content+= "   }\n"
    else:
        content+= "   if (i<0 || i>(int)Pt.GetSize()) {\n"
        content+= "      cout << i << endl;\n"
        content+= "      return false;\n"
        content+= "   }\n"

    content+= "   return "+instruction+";\n"
    content+= "}\n"
    return content

# Generation lines of code to add the method and the label into vectors
def HSCPSelectorAddLabelsAndPointers2Vector(label):
   content = "selections_.push_back(&HSCPSelector::PassHSCPpresel_"+label+");\n"
   content+= "selLabels_.push_back(\""+label+"\");\n"
   return content


# The 3 functions below generate the codes for all preselection found in a pandas dataframe called df
# (row.iloc[0] is the label, row.iloc[1] the C++ expression)

def Code_HSCPSelectorProto(df):
    code = ""
    for index, row in df.iterrows():
        if IsCommented(row.iloc[0]):
            continue
        code+=HSCPSelectorProto(row.iloc[0])+"\n"
    return code

def Code_HSCPSelectorImpl(df):
    code = ""
    for index, row in df.iterrows():
        if IsCommented(row.iloc[0]): continue
        code+=HSCPSelectorImpl(row.iloc[0],row.iloc[1])+"\n"
    return code

def Code_HSCPSelectorAddLabelsAndPointers2Vector(df):
    code = ""
    for index, row in df.iterrows():
        if IsCommented(row.iloc[0]): continue
        code+=HSCPSelectorAddLabelsAndPointers2Vector(row.iloc[0])+"\n"
    return code
