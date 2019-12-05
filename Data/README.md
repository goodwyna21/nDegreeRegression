USPopData.tsv:
Yearly Population of USA since 1960

    Source: https://fred.stlouisfed.org/series/POPTOTUSA647NWDB
    Format:
        Line 0: Num_Test1 Num_Train Num_Test1
        Lines: Num Population  Year
    Delimiter: "    " (tab)

    Training (39): [10, 48]
        year:    [1970, 2008]

    Testing (20):     [0, 9] U [49, 58]
      year:     [1960, 1969] U [2009, 2018]
