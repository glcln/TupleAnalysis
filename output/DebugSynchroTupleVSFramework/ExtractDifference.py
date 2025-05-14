import re
import collections

# Extraire les event et I_h d'un fichier
def extract_events(file_path):
    events = []
    Ih = []
    with open(file_path, 'r') as file:
        for line in file:
            matchEvent = re.search(r"event:(\d+)", line)
            matchIh = re.search(r"Ih:(\d+)", line)
            if matchEvent:
                events.append(matchEvent.group(1))
            if matchIh:
                Ih.append(matchIh.group(1))
    return events, Ih


# Setup
Histos = 'CheckLocalHistos_Region.txt'
Tuples = 'CheckLocalTuples_Region_corr.txt'

EventHistos, IhHistos = extract_events(Histos)
EventTuples, IhTuples = extract_events(Tuples)

OnlyInHistos = list(set(EventHistos) - set(EventTuples))
OnlyInTuples = list(set(EventTuples) - set(EventHistos))


# Debug
print("#Event Histos: ", len(EventHistos))
print("#Event Tuples: ", len(EventTuples))

print("Event que dans Histos et pas dans Tuples: ", OnlyInHistos)
for event in OnlyInHistos:
    for line in open(Histos):
        if event in line:
            print(line)
print("Event que dans Tuples et pas dans Histos: ", OnlyInTuples)
for event in OnlyInTuples:
    for line in open(Tuples):
        if event in line:
            print(line)

DoublonsHistos = [item for item, count in collections.Counter(EventHistos).items() if count > 1]
print("Event doublons dans Histos: ", DoublonsHistos)
DoublonsTuples = [item for item, count in collections.Counter(EventTuples).items() if count > 1]
print("Event doublons dans Tuples: ", DoublonsTuples)

print("\nCaracteristique des doublons Histos: ")
for event in DoublonsHistos:
    for line in open(Histos):
        if event in line:
            print(line)
print("\nCaracteristique des doublons Tuples: ")
for event in DoublonsTuples:
    for line in open(Tuples):
        if event in line:
            print(line)
