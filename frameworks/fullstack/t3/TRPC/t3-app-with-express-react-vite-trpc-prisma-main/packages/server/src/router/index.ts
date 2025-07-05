// Router of functions exposed by the trpc.

import { trpc } from "../lib/trpc";
import { todoRouter } from "./todoRouter";

// Here we merge all the routers of the application, In this case, there is only one
// router which is todoRouter

export const appRouter = trpc.router({
    todo: todoRouter
})

export type AppRouter = typeof appRouter;