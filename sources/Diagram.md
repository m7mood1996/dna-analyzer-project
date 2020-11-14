# cpp-ood-dna-sequence-m7mood1996


## DNA Class diagram
```plantuml

class DnaSequence{
    -size: size_t 
    -nucleotides: Nucleotide
    -name: string
    +DnaSequence(char*): DnaSequence
    +DnaSequence(string): DnaSequence
    +DnaSequence(DnaSequence&): DnaSequence
    +getLength(): size_t
    +getName():string
    -setName(string)

}

class Nucleotide {
    -m_type : char 
    +Nucleotide() : Nucleotide
    +getType(): char
    +setType(char) 

}
DnaSequence "1"*---"1..*" Nucleotide
DnaSequenceFile -right-|> DnaSequence
DnaSequencePairing -left-|> DnaSequence
DnaSequenceSearch --|> DnaSequence
DnaSequenceMinipulation --|> DnaSequence


class DnaSequenceFile {
    +ReadSequenceFromFile(char *): DnaSequence
    +WriteSequencetoFile(const DnaSequence&): bool
}

class DnaSequencePairing {

    +Pairing(DnaSequence& dnaSequence): DnaSequence 

}

class DnaSequenceSearch {

    +Find(DnaSequence, DnaSequence): size_t
    +Count(DnaSequence, DnaSequence): size_t
    +FindAll(DnaSequence, DnaSequence): list<size_t>
    +FindConsensusSequences(DnaSequence): list<size_t> 

}

class DnaSequenceMinipulation {

    +Slice(DnaSequence , from: size_t, to:size_t): DnaSequence

}

```

# Packeges

```plantuml
package DNA {

    package DnaSequence{}

    package FileIO{}

    package DNA_Minpulate {}

    package DNA_Analyze {}

}
package CLI {}

CLI ---> DNA
```

# Usecase 
```plantuml
:User:
rectangle System {
(DNA Analyze)
(Load DNA)
(Store DNA)
(Minpulate DNA)
(quit)
}
:DB: <-- (Load DNA) 
(Store DNA) --> :DB:

rectangle CLI{
    (CLI cmd)
}
:User: -up->(CLI cmd)
(CLI cmd) -up-> (Load DNA)
(CLI cmd) -up-> (Store DNA)
(CLI cmd) -up-> (Minpulate DNA)
(CLI cmd) -up-> (DNA Analyze)





```
