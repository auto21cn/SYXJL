#include <ansi.h>
inherit SKILL;

mapping *quest = ({
        ([      "quest":               "����",
                "quest_type":           "ɱ",
                "time":                 600,
                "score" :               6
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                 200,
                "score" :               3
        ]),
        ([      "quest":                "���ͷ",
                "quest_type":           "ɱ",
                "time":                 400,
                "score" :               5
        ]),
        ([      "quest":                "�Ҷ�",
                "quest_type":           "ɱ",
                "time":                 400,
                "score" :               5
        ]),
        ([      "quest":                "�ܼ�",
                "quest_type":           "ɱ",
                "time":                 400,
                "score" :               5
        ]),
        ([      "quest":                "С��å",
                "quest_type":           "ɱ",
                "time":                 500,
                "score" :               8
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 500,
                "score" :               8
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɨ",
                "time":                 200,
                "score" :               6
        ]),
        ([      "quest":                "�ؾ���",
                "quest_type":           "ɨ",
                "time":                 200,
                "score" :               3
        ]),
        ([      "quest":                "��������",
                "quest_type":           "ɱ",
                "time":                 420,
                "score" :               6
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                 200,
                "score" :               6
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                 400,
                "score" :               7
        ]),
        ([      "quest":                "��Ѽ",
                "quest_type":           "Ѱ",
                "time":                 200,
                "score" :               3
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 650,
                "score" :               7
        ]),
});

mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
