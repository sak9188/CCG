import re, pathlib
base = pathlib.Path("/home/engine/project")
files = []
for p in base.glob("CCG/**/*.h"): files.append(p)
for p in base.glob("CCG/**/*.cpp"): files.append(p)
files.append(base/"CCG/CMakeLists.txt")
files.append(base/"CMakeLists.txt")
files = [p for p in files if p.exists()]

include_map = {
    "CGGGame.h": "cgg_game.h",
    "WINEventActor.h": "win_event_actor.h",
    "eventActor.h": "event_actor.h",
    "renderActor.h": "render_actor.h",
    "gameObject.h": "game_object.h",
    "sceneItem.h": "scene_item.h",
    "cardStack.h": "card_stack.h",
    "CCG_constant.h": "ccg_constant.h",
    "enum/CCG_enum.h": "enum/ccg_enum.h",
    "../gameObject.h": "../game_object.h",
    "../enum/CCG_enum.h": "../enum/ccg_enum.h",
    "CCG.cpp": "ccg.cpp",
    "CGGGame.cpp": "cgg_game.cpp",
    "WINEventActor.cpp": "win_event_actor.cpp",
    "gameObject.cpp": "game_object.cpp",
    "renderActor.cpp": "render_actor.cpp",
    "sceneItem.cpp": "scene_item.cpp",
    "cardStack.cpp": "card_stack.cpp",
}

class_map = [
    (r"\bCGGGame\b", "cgg_game"),
    (r"\bWINEventActor\b", "win_event_actor"),
    (r"\bRenderAcotor\b", "render_acotor"),
    (r"\bEventActor\b", "event_actor"),
    (r"\bSceneItem\b", "scene_item"),
    (r"\bScene\b", "scene"),
    (r"\bGameObject\b", "game_object"),
    (r"\bGameround\b", "gameround"),
    (r"\bRecorder\b", "recorder"),
    (r"\bCardStack\b", "card_stack"),
    (r"\bCharactor\b", "charactor"),
    (r"\bProfession\b", "profession"),
    (r"\bCard\b", "card"),
    (r"\bCreature\b", "creature"),
    (r"\bMedia\b", "media"),
    (r"\bArena\b", "arena"),
]

for path in files:
    text = path.read_text(encoding="utf-8", errors="ignore")
    orig = text
    for old, new in include_map.items():
        text = text.replace(old, new)
    for pattern, repl in class_map:
        text = re.sub(pattern, repl, text)
    if text != orig:
        path.write_text(text, encoding="utf-8")
        print("Updated:", path.relative_to(base))
